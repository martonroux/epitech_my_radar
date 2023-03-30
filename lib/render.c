/*
** EPITECH PROJECT, 2023
** github_test
** File description:
** render.c
*/

#include "../include/my.h"

void render_areas(data *data, sfRenderWindow * window)
{
    if (!data->game_data->show_areas)
        return;
    for (int i = 0; i < data->game_data->nb_areas; i++) {
        sfRenderWindow_drawRectangleShape(
            window,
            data->areas[i].area,
            NULL
            );
    }
}

void render_planes(data * data, sfRenderWindow * window)
{
    plane * actual = data->plane;
    int nb_planes = 0;

    while (actual) {
        if (check_out_of_screen(actual) || actual->data->destroy_plane) {
            ll_delete(actual, data);
            actual = actual->next;
            continue;
        }
        if (data->game_data->show_elems)
            sfRenderWindow_drawSprite(window, actual->data->sprite, NULL);
        if (data->game_data->show_areas)
            sfRenderWindow_drawRectangleShape(window, actual->data->area, NULL);
        actual = actual->next;
        nb_planes++;
    }
    data->game_data->nb_planes = nb_planes;
}

void render_towers(data * data, sfRenderWindow * window)
{
    for (int i = 0; i < data->game_data->nb_towers; i++) {
        if (data->game_data->show_areas)
            sfRenderWindow_drawCircleShape(window, data->towers[i]->area, NULL);
        if (data->game_data->show_elems)
            sfRenderWindow_drawSprite(window, data->towers[i]->sprite, NULL);
    }
}

void destroy_elems(data *data, sfRenderWindow *window)
{
    plane *actual = data->plane;

    sfRenderWindow_destroy(window);
    for (int i = 0; i < data->game_data->nb_areas; i++)
        sfRectangleShape_destroy(data->areas[i].area);
    for (int i = 0; i < data->game_data->nb_towers; i++) {
        sfCircleShape_destroy(data->towers[i]->area);
        sfSprite_destroy(data->towers[i]->sprite);
        free(data->towers[i]);
    }
    while (actual) {
        sfSprite_destroy(actual->data->sprite);
        sfRectangleShape_destroy(actual->data->area);
        actual = actual->next;
    }
}

void render(data *data)
{
    sfRenderWindow * window = data->window.window;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &data->window.event));
        sfRenderWindow_clear(window, sfBlack);
        check_area(data);
        check_collision(data);
        render_areas(data, window);
        render_planes(data, window);
        render_towers(data, window);
        display_timer(data, window);
        display_fps(data, window);
        display_nb_planes(data, window);
        move_planes(data);
        key_pressing(data);
        sfRenderWindow_display(window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) || test_game_ends(data))
            sfRenderWindow_close(window);
    }
    destroy_elems(data, window);
}
