/*
** EPITECH PROJECT, 2022
** B_MUL
** File description:
** my_sfintrect_col.c
*/

#include "../include/my.h"

int my_sfintrect_col(sfIntRect *rect, int x, int y, int size)
{
    size /= 2;

    if (x - size >= rect->left && x - size <= rect->left + rect->width)
        if (y - size >= rect->top && y - size <= rect->top + rect->height)
            return 1;

    if (x + size >= rect->left && x + size <= rect->left + rect->width)
        if (y - size >= rect->top && y - size <= rect->top + rect->height)
            return 1;

    if (x - size >= rect->left && x - size <= rect->left + rect->width)
        if (y + size >= rect->top && y + size <= rect->top + rect->height)
            return 1;

    if (x + size >= rect->left && x + size <= rect->left + rect->width)
        if (y + size >= rect->top && y + size <= rect->top + rect->height)
            return 1;
    return 0;
}
