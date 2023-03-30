/*
** EPITECH PROJECT, 2023
** github_test
** File description:
** init_data_bis.c
*/

#include "../include/my.h"

window init_window(void)
{
    window res;

    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    res.window = sfRenderWindow_create(
        mode, "my_radar",
        sfFullscreen | sfClose | sfResize,
        NULL);
    sfRenderWindow_setFramerateLimit(res.window, 60);
    return res;
}

areas init_data_area(int nb_areas, int i)
{
    areas res;
    int width = WINDOW_WIDTH / nb_areas;
    int height = WINDOW_HEIGHT / nb_areas;
    int left = width * (int)(i % (int)nb_areas);
    int top = height * (int)(i / (int)nb_areas);

    sfIntRect rect = {left, top, width, height};
    res.area = sfRectangleShape_create();
    res.rect = rect;
    sfRectangleShape_setFillColor(res.area, sfTransparent);
    sfRectangleShape_setOutlineThickness(res.area, 1);
    sfRectangleShape_setOutlineColor(res.area, sfWhite);
    sfRectangleShape_setSize(res.area,(sfVector2f){width, height});
    sfRectangleShape_setPosition(
        res.area,
        (sfVector2f){(float)left, (float)top}
    );
    return res;
}

areas * init_area(int nb_areas)
{
    areas * res = malloc(sizeof(areas) * nb_areas * nb_areas);

    for (int i = 0; i < nb_areas * nb_areas; i++) {
        res[i] = init_data_area(nb_areas, i);
    }
    return res;
}

quarantine ** init_quarantine(int nb_areas, int nb_planes)
{
    quarantine ** res = malloc(sizeof(quarantine *) * nb_areas * nb_areas);

    for (int i = 0; i < nb_areas * nb_areas; i++) {
        res[i] = malloc(sizeof(quarantine));
        res[i]->data = malloc(sizeof(plane_data) * nb_planes);
        res[i]->nb_planes = 0;
    }
    return res;
}
