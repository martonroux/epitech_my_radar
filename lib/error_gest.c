/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** error_gest.c
*/

#include "../include/my.h"

int test_line_bis(char *str)
{
    int nb_numbers = 0;

    for (int i = 1; str[i]; i++) {
        while (str[i] == ' ')
            i++;
        while (is_num(str[i])) {
            nb_numbers += (str[i - 1] == ' ') ? 1 : 0;
            i++;
        }
    }
    if (str[0] == 'A' && nb_numbers != 6) {
        write(2, "A plane in the file doesn't have enough numbers\n", 48);
        return 84;
    }
    if (str[0] == 'T' && nb_numbers != 3) {
        write(2, "A tower in the file doesn't have enough numbers\n", 48);
        return 84;
    }
    return 0;
}

int test_line(char * str)
{
    if (str[0] != 'A' && str[0] != 'T') {
        write(2, "Invalid character: expected 'A' or 'T'\n", 39);
        return 84;
    }
    for (int i = 1; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\n' && !is_num(str[i])) {
            write(2, "Invalid character found in file\n", 32);
            return 84;
        }
    }
    return test_line_bis(str);
}

int test_validity_file(char * filename)
{
    FILE *ptr = fopen(filename, "r");
    char *res = malloc(sizeof(char) * 255);
    size_t bytes = 254;

    while (getline(&res, &bytes, ptr) != ULLONG_MAX) {
        if (test_line(res) == 84)
            return 84;
    }
    return 0;
}

void display_help(void)
{
    write(1, "This program displays planes and towers on the screen, ", 55);
    write(1, "their position, speed and delays (for planes), and", 50);
    write(1, " radius (for towers), given in the file in parameter.\n", 54);
    write(1, "\n\tUsage: ./my_radar <file_name>\n\n", 33);
    write(1, "The following commands are to use:\n", 35);
    write(1, "'L': toggles display of areas/chunks/collide boxes.\n", 52);
    write(1, "'S': toggles display of textures.\n", 34);
    write(1, "'A': accelerates planes speed.\n", 31);
    write(1, "'D': decelerates planes speed.\n", 31);
    write(1, "'Esc': closes the game.\n", 24);
}

int error_gest(int argc, char ** argv)
{
    if (argc < 2) {
        write(2, "Not enough arguments. -h for more info\n", 39);
        return 84;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        display_help();
        return 84;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        write(2, "File given isn't accessible\n", 28);
        return 84;
    }
    close(fd);
    return test_validity_file(argv[1]);
}
