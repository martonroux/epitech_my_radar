/*
** EPITECH PROJECT, 2022
** B_MUL
** File description:
** error_gest.c
*/

#include "gen.h"

void display_sintax(int with_h)
{
    int fd = (with_h == 1) ? 1 : 2;
    if (with_h) {
        write(1, "This file generator allows you to create files for ", 51);
        write(1, "the my_radar project. Every coordinate is ", 42);
        write(1, "generated randomly with boundaries set by the ", 46);
        write(1, "corresponding global variable in gen.h file.", 44);
        write(1, "Feel free to change them as you like.\n\n", 39);
    }
    write(fd, "Syntax:\n\t./file_generator <file_name> <nb_planes>", 49);
    write(fd, " <nb_towers>\n", 13);
    if (!with_h)
        write(fd, "Use -h for more info\n", 21);
}

int is_number(char *str)
{
    while (*str) {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

int is_file(char *file_path)
{
    int fd = open(file_path, O_RDONLY);

    if (fd < 0) {
        close(fd);
        return 0;
    }
    close(fd);
    return 1;
}

int error_gest(int argc, char **argv)
{
    if (argc < 4) {
        if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
            display_sintax(1);
            return 84;
        }
        display_sintax(0);
        return 84;
    }
    if (!is_number(argv[2]) || !is_number(argv[3])) {
        display_sintax(0);
        return 84;
    }
    if (!is_file(argv[1])) {
        display_sintax(0);
        return 84;
    }
    return 0;
}
