/*
** EPITECH PROJECT, 2022
** B_MUL
** File description:
** square_collision.c
*/

#include "../../include/my.h"

int square_collision(sfRectangleShape *sqr1, sfRectangleShape *sqr2)
{
    sfVector2f bounds_r1 = sfRectangleShape_getSize(sqr1);
    sfVector2f bounds_r2 = sfRectangleShape_getSize(sqr2);
    sfVector2f pos_r1 = sfRectangleShape_getPosition(sqr1);
    sfVector2f pos_r2 = sfRectangleShape_getPosition(sqr2);
    float cx = pos_r1.x;
    float dx = pos_r2.x;
    float cy = pos_r1.y;
    float dy = pos_r2.y;
    float sqr_r = bounds_r1.x / 2;
    float cr_r = bounds_r2.x / 1.5f;

    if (((cx - dx) * (cx - dx)) + ((cy - dy) * (cy - dy)) <=
        (sqr_r + cr_r) * (sqr_r + cr_r))
        return 1;
    return 0;
}
