/*
** EPITECH PROJECT, 2023
** github_test
** File description:
** check_area.c
*/

#include "../include/my.h"

void assign_areas(plane * actual, areas * areas, int nb_ar, quarantine ** qrt)
{
    sfVector2f pos = sfRectangleShape_getPosition(actual->data->area);
    int k;

    for (int i = 0; i < nb_ar; i++) {
        k = qrt[i]->nb_planes;
        if (my_sfintrect_col(
                &areas[i].rect,
                (int)pos.x,
                (int)pos.y,
                (int)actual->data->size
                )) {
            qrt[i]->data[k] = actual->data;
            qrt[i]->nb_planes++;
        }
    }
}

void check_area(data * data)
{
    plane *actual = data->plane;
    int nb_areas = data->game_data->nb_areas;

    for (int i = 0; i < nb_areas; i++)
        data->quarantine[i]->nb_planes = 0;

    while (actual) {
        assign_areas(actual, data->areas, nb_areas, data->quarantine);
        actual = actual->next;
    }
}

int check_out_of_screen(plane * plane)
{
    sfVector2f pos = sfRectangleShape_getPosition(plane->data->area);

    if (pos.x < 0 || pos.x > WINDOW_WIDTH)
        return 1;
    if (pos.y < 0 || pos.y > WINDOW_HEIGHT)
        return 1;
    return 0;
}
