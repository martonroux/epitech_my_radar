/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** init_data_quad.c
*/

#include "../include/my.h"

void init_text(sfText * text, sfVector2f pos, sfColor color, sfFont * font)
{
    sfText_setFont(text, font);
    sfText_setFillColor(text, color);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
}

game_data * init_game_data(int nb_areas, int nb_towers, int nb_planes)
{
    game_data * res = malloc(sizeof(game_data));
    sfFont * font = sfFont_createFromFile("fonts/arial_narrow_7.ttf");
    sfVector2f timer_pos = {WINDOW_WIDTH - 200, 80};
    sfVector2f fps_pos = {WINDOW_WIDTH - 200, 20};
    sfVector2f planes_pos = {WINDOW_WIDTH - 200, 140};

    res->nb_planes = nb_planes;
    res->nb_areas = nb_areas * nb_areas;
    res->nb_towers = nb_towers;
    res->clock = sfClock_create();
    res->timer_text = sfText_create();
    init_text(res->timer_text, timer_pos,sfCyan, font);
    sfText_setString(res->timer_text, "Timer: 0");
    res->fps_text = sfText_create();
    init_text(res->fps_text, fps_pos,sfRed, font);
    sfText_setString(res->timer_text, "0 FPS");
    res->planes_text = sfText_create();
    init_text(res->planes_text, planes_pos,sfCyan, font);
    sfText_setString(res->timer_text, "Planes: 0");
    return res;
}
