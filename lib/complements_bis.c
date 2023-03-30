/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** complements_bis.c
*/

#include "../include/my.h"

char * concat_str(char * str_1, char * str_2)
{
    int len_1 = my_strlen(str_1);
    int len_2 = my_strlen(str_2);
    char * result = malloc(sizeof(char) * (len_1 + len_2 + 1));
    result[len_1 + len_2] = '\0';
    int i = 0;

    for (int j = 0; str_1[j]; j++) {
        result[i] = str_1[j];
        i++;
    }
    for (int j = 0; str_2[j]; j++) {
        result[i] = str_2[j];
        i++;
    }
    return result;
}

void display_nb_planes(data * data, sfRenderWindow * window)
{
    char * nb = get_number(data->game_data->nb_planes);
    char * str = concat_str("Planes: ", nb);

    sfText_setString(data->game_data->planes_text, str);
    sfRenderWindow_drawText(window, data->game_data->planes_text, NULL);
}
