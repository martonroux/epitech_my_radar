/*
** EPITECH PROJECT, 2023
** github_test
** File description:
** actions_main.c
*/

#include "../include/my.h"

void move_planes_sec(plane *actual, int game_speed)
{
    sfVector2f arrival = actual->data->dest;
    sfVector2f departure = actual->data->origin;
    float angle = atan2f(arrival.y - departure.y, arrival.x - departure.x);
    sfVector2f pos = sfSprite_getPosition(actual->data->sprite);
    sfVector2f new_pos = {
        pos.x + cos(angle) * actual->data->speed / game_speed,
        pos.y + sin(angle) * actual->data->speed / game_speed
    };
    sfSprite_setPosition(actual->data->sprite, new_pos);
    sfRectangleShape_setPosition(actual->data->area, new_pos);
    sfSprite_setRotation(actual->data->sprite, angle * 180 / 3.14);
    sfRectangleShape_setRotation(actual->data->area, angle * 180 / 3.14);
}

void test_plane_arrived(plane * plane, data * data)
{
    sfVector2f pos;
    sfVector2f departure;
    sfVector2f arrival;

    arrival = plane->data->dest;
    departure = plane->data->origin;
    pos = sfSprite_getPosition(plane->data->sprite);
    if (arrival.x < departure.x) {
        pos.x = 1 / pos.x;
        arrival.x = 1 / arrival.x;
    }
    if (arrival.y < departure.y) {
        pos.y = 1 / pos.y;
        arrival.y = 1 / arrival.y;
    }
    if (pos.x >= arrival.x && pos.y >= arrival.y)
        ll_delete(plane, data);
}

void move_planes(data * data)
{
    plane *actual = data->plane;
    sfTime time = sfClock_getElapsedTime(data->game_data->clock);
    float seconds = (float)time.microseconds / 1000000.0f;

    while (actual) {
        if (seconds > (float)actual->data->delay) {
            move_planes_sec(actual, data->game_data->game_speed);
            test_plane_arrived(actual, data);
        }
        actual = actual->next;
    }
}

void key_pressing_bis(data * data)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        if (data->game_data->show_elems)
            data->game_data->show_elems = 0;
        else
            data->game_data->show_elems = 1;
        data->game_data->key_pressed = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        if (data->game_data->game_speed > 5.f)
            data->game_data->game_speed -= 5.f;
        data->game_data->key_pressed = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        data->game_data->game_speed += 5.f;
        data->game_data->key_pressed = 1;
    }
}

void key_pressing(data * data)
{
    if (data->game_data->key_pressed) {
        if (data->window.event.type == sfEvtKeyReleased)
            data->game_data->key_pressed = 0;
        else
            return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyL)) {
        if (data->game_data->show_areas)
            data->game_data->show_areas = 0;
        else
            data->game_data->show_areas = 1;
        data->game_data->key_pressed = 1;
    }
    key_pressing_bis(data);
}
