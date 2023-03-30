/*
** EPITECH PROJECT, 2023
** github_test
** File description:
** check_collision.c
*/

#include "../include/my.h"

int check_if_in_tower(sfRectangleShape * r_1, tower ** towers, int nb_towers)
{
    for (int i = 0; i < nb_towers; i++) {
        if (collision("cr", towers[i]->area, r_1)) {
            return 1;
        }
    }
    return 0;
}

void area_specific_collide_bis(
    quarantine * quarantine, int j, int i, sfRectangleShape * r_1
    )
{
    if (quarantine->data[j]->destroy_plane)
        return;
    sfRectangleShape * r_2 = quarantine->data[j]->area;

    if (collision("rr", r_1, r_2)) {
        quarantine->data[i]->destroy_plane = 1;
        quarantine->data[j]->destroy_plane = 1;
    }
}

void area_specific_collide(quarantine * quarantine, tower ** towers, int nb_tow)
{
    int max = quarantine->nb_planes;

    for (int i = 0; i < max - 1; i++) {
        if (quarantine->data[i]->destroy_plane)
            continue;
        sfRectangleShape * r_1 = quarantine->data[i]->area;

        if (check_if_in_tower(r_1, towers, nb_tow))
            continue;

        for (int j = i + 1; j < max; j++) {
            area_specific_collide_bis(quarantine, j, i, r_1);
        }
    }
}

void check_collision(data *data)
{
    int nb_areas = data->game_data->nb_areas;

    for (int i = 0; i < nb_areas; i++) {
        area_specific_collide(
            data->quarantine[i],
            data->towers,
            data->game_data->nb_towers
            );
    }
}
