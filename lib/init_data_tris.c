/*
** EPITECH PROJECT, 2023
** github_test
** File description:
** init_data_tri.c
*/

#include "../include/my.h"

void init_data_plane(plane_data *res, const int *numbers)
{
    sfVector2f pos = {(float)numbers[1], (float)numbers[2]};
    float size = rand() % MAX_PLANE_HITBOX_SIZE + 10;

    sfSprite_setOrigin(res->sprite, (sfVector2f){2.5f, 2.5f});
    sfSprite_setPosition(res->sprite, pos);
    sfSprite_setScale(res->sprite, (sfVector2f){6.f, 6.f});
    sfRectangleShape_setSize(res->area, (sfVector2f){size, size});
    sfRectangleShape_setFillColor(res->area, sfTransparent);
    sfRectangleShape_setOutlineColor(res->area, sfWhite);
    sfRectangleShape_setOutlineThickness(res->area, 1);
    sfRectangleShape_setOrigin(res->area, (sfVector2f){size / 2, size / 2});
    sfRectangleShape_setPosition(res->area, pos);
    res->size = size;
}

plane_data * init_plane(int * numbers)
{
    plane_data *res = malloc(sizeof(plane_data));
    sfTexture *texture = sfTexture_createFromFile("sprites/plane_3.png", NULL);
    sfVector2f pos = {(float)numbers[1], (float)numbers[2]};

    res->sprite = sfSprite_create();
    sfSprite_setTexture(res->sprite, texture, sfTrue);
    res->area = sfRectangleShape_create();
    init_data_plane(res, numbers);
    res->origin = pos;
    res->dest = (sfVector2f){(float)numbers[3], (float)numbers[4]};
    res->speed = numbers[5];
    res->delay = numbers[6];
    res->destroy_plane = 0;
    return res;
}

void init_data_tower(tower * res, const int *numbers)
{
    float radius = WINDOW_WIDTH * (float)numbers[3] / 100;
    sfVector2f origin = {radius,radius};
    sfVector2f pos = {(float)numbers[1], (float)numbers[2]};

    sfSprite_setOrigin(res->sprite, (sfVector2f){256, 256});
    sfSprite_setPosition(res->sprite,pos);
    sfSprite_setScale(res->sprite, (sfVector2f){0.15f, 0.15f});
    sfCircleShape_setRadius(res->area, radius);
    sfCircleShape_setOrigin(res->area, origin);
    sfCircleShape_setPosition(res->area,pos);
    sfCircleShape_setFillColor(res->area, sfTransparent);
    sfCircleShape_setOutlineColor(res->area, sfWhite);
    sfCircleShape_setOutlineThickness(res->area, 2);
}

tower * create_tower(int * numbers)
{
    tower * res = malloc(sizeof(tower));
    sfTexture *texture = sfTexture_createFromFile("sprites/tower.png", NULL);

    res->sprite = sfSprite_create();
    sfSprite_setTexture(res->sprite, texture, sfTrue);
    res->area = sfCircleShape_create();
    init_data_tower(res, numbers);
    res->radius = numbers[3];
    return res;
}

tower ** init_towers(int ** numbers, int nb_towers)
{
    tower ** res = malloc(sizeof(tower *) * (nb_towers + 1));
    res[nb_towers] = NULL;
    nb_towers = 0;

    for (int i = 0; numbers[i][0] != -1; i++) {
        if (numbers[i][0] == 0) {
            res[nb_towers] = create_tower(numbers[i]);
            nb_towers++;
        }
    }
    return res;
}
