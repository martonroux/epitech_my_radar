/*
** EPITECH PROJECT, 2023
** github_test
** File description:
** main.c
*/

#include "include/my.h"

int main(int argc, char **argv)
{
    if (error_gest(argc, argv) == 84)
        return 84;
    srand(time(NULL));
    int ** numbers = parsing(argv[1]);
    data *data = init_data(6, numbers);
    render(data);
    return 0;
}
