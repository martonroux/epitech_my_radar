/*
** EPITECH PROJECT, 2023
** github_test
** File description:
** init_data.c
*/

#include "../include/my.h"

void get_numbers(char **array, int i, int **result)
{
    int limit = (result[i][0] == 0) ? 3 : 6;
    array[i] += 1;
    while (array[i][0] == ' ')
        array[i]++;
    for (int j = 1; j <= limit; j++) {
        int *number = my_get_nbr(array[i]);
        result[i][j] = number[0];
        array[i] += number[1];
        while (array[i][0] == ' ')
            array[i]++;
    }
}

int ** create_numbers(char **array)
{
    int **result;
    int nb_elem = 0;
    for (; array[nb_elem]; nb_elem++);
    result = malloc(sizeof(int *) * (nb_elem + 1));
    for (int i = 0; i < nb_elem + 1; i++)
        result[i] = malloc(sizeof(int) * 8);

    for (int i = 0; i < nb_elem; i++) {
        if (array[i][0] == 'A')
            result[i][0] = 1;
        else
            result[i][0] = 0;
        get_numbers(array, i, result);
    }
    result[nb_elem][0] = -1;
    result[0][7] = nb_elem;
    return result;
}

int ** parsing(char *filename)
{
    char *temp = malloc(sizeof(char) * 256);
    size_t n = 256;
    FILE *file = fopen(filename, "r");
    int file_len = 0;

    if (!file) {
        write(2, "File not found\n", 15);
        return NULL;
    }
    while (getline(&temp, &n, file) != ULLONG_MAX)
        file_len++;
    fclose(file);
    file = fopen(filename, "r");
    char **result = malloc(sizeof(char *) * (file_len + 1));
    for (int i = 0; i < file_len; i++)
        result[i] = malloc(sizeof(char) * 256);
    for (int i = 0; i < file_len; i++)
        getline(&result[i], &n, file);
    result[file_len] = NULL;
    return create_numbers(result);
}

data * init_data_bis(int nb_areas, int nb_planes, int nb_towers, data * res)
{
    res->window = init_window();
    res->areas = init_area(nb_areas);
    res->quarantine = init_quarantine(nb_areas, nb_planes);
    res->game_data = init_game_data(nb_areas, nb_towers, nb_planes);
    res->game_data->key_pressed = 0;
    res->game_data->show_elems = 1;
    res->game_data->show_areas = 1;
    res->game_data->game_speed = 60;
    return res;
}

data * init_data(int nb_areas, int ** numbers)
{
    data * result = malloc(sizeof(data));
    int nb_planes = 0;
    int nb_towers = 0;
    for (int i = 0; numbers[i][0] != -1; i++) {
        if (nb_planes == 0 && numbers[i][0] == 1) {
            plane_data *data = init_plane(numbers[i]);
            result->plane = ll_create(data);
            nb_planes++;
            continue;
        }
        if (numbers[i][0] == 1) {
            plane_data *data = init_plane(numbers[i]);
            ll_add(data, result);
            nb_planes++;
        } else
            nb_towers++;
        print_progression(numbers[0][7], i);
    }
    result->towers = init_towers(numbers, nb_towers);
    return init_data_bis(nb_areas, nb_planes, nb_towers, result);
}
