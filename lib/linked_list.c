/*
** EPITECH PROJECT, 2023
** github_test
** File description:
** linked_list.c
*/

#include "../include/my.h"

plane * ll_create(plane_data * data)
{
    plane * res = malloc(sizeof(plane));

    res->data = data;
    res->next = NULL;
    res->previous = NULL;
    return res;
}

void ll_add(plane_data * value, data * data)
{
    plane * new = malloc(sizeof(plane));

    new->data = value;
    new->next = data->plane;
    new->previous = NULL;

    if (data->plane != NULL)
        data->plane->previous = new;
    data->plane = new;
}

void ll_delete(plane * plane, data * data)
{
    if (data->plane == NULL || plane == NULL)
        return;

    if (plane == data->plane)
        data->plane = plane->next;

    if (plane->next != NULL)
        plane->next->previous = plane->previous;

    if (plane->previous != NULL)
        plane->previous->next = plane->next;
}
