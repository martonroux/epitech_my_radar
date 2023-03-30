/*
** EPITECH PROJECT, 2022
** B_MUL
** File description:
** multi_type.c
*/

#include "collision.h"

int square_and_circle(sfRectangleShape *sqr, sfCircleShape *cr)
{
    sfVector2f pos = sfRectangleShape_getPosition(sqr);
    float cx = pos.x;
    float cy = pos.y;
    pos = sfCircleShape_getPosition(cr);
    float dx = pos.x;
    float dy = pos.y;
    float sqr_r = sfRectangleShape_getSize(sqr).x / 2;
    float cr_r = sfCircleShape_getRadius(cr);

    if (((cx - dx) * (cx - dx)) + ((cy - dy) * (cy - dy)) <=
            (sqr_r + cr_r) * (sqr_r + cr_r))
        return 1;
    return 0;
}
