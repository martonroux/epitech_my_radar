/*
** EPITECH PROJECT, 2022
** B_MUL
** File description:
** file_generator.c
*/

#include "gen.h"

void write_number(int nb, FILE *ptr)
{
    char *str = number_to_str(nb);
    int len = my_nb_len(nb);

    fwrite(str, sizeof(char), len, ptr);
}

void write_tower_line(FILE *ptr)
{
    int pos_x = rand() % (WINDOW_WIDTH - 2) + 1;
    int pos_y = rand() % (WINDOW_HEIGHT - 2) + 1;
    int radius = rand() % RADIUS_MAX_TOWER;

    fwrite("T ", sizeof(char), 2, ptr);
    write_number(pos_x, ptr);
    fwrite(" ", sizeof(char), 1, ptr);
    write_number(pos_y, ptr);
    fwrite(" ", sizeof(char), 1, ptr);
    write_number(radius, ptr);
    fwrite("\n", sizeof(char), 1, ptr);
}

void write_plane_line(FILE *ptr)
{
    int origin_x = rand() % WINDOW_WIDTH;
    int origin_y = rand() % WINDOW_HEIGHT;
    int dest_x = rand() % WINDOW_WIDTH;
    int dest_y = rand() % WINDOW_HEIGHT;
    int speed = rand() % SPEED_MAX_PLANE + 1;
    int delay = rand() % DELAY_MAX_PLANE;

    fwrite("A ", sizeof(char), 2, ptr);
    write_number(origin_x, ptr);
    fwrite(" ", sizeof(char), 1, ptr);
    write_number(origin_y, ptr);
    fwrite(" ", sizeof(char), 1, ptr);
    write_number(dest_x, ptr);
    fwrite(" ", sizeof(char), 1, ptr);
    write_number(dest_y, ptr);
    fwrite(" ", sizeof(char), 1, ptr);
    write_number(speed, ptr);
    fwrite(" ", sizeof(char), 1, ptr);
    write_number(delay, ptr);
    fwrite("\n", sizeof(char), 1, ptr);
}

void gen_data(char **argv)
{
    FILE *ptr = fopen(argv[1], "w");
    int nb_planes = my_get_nbr(argv[2]);
    int nb_towers = my_get_nbr(argv[3]);
    srand(time(NULL));

    for (int i = 0; i < nb_planes; i++) {
        write_plane_line(ptr);
    }
    for (int i = 0; i < nb_towers; i++) {
        write_tower_line(ptr);
    }
}

int main(int argc, char **argv)
{
    if (error_gest(argc, argv) == 84)
        return 84;
    gen_data(argv);
    return 0;
}
