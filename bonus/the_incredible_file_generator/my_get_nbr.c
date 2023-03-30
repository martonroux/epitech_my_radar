/*
** EPITECH PROJECT, 2022
** B_MUL
** File description:
** my_get_nbr.c
*/

#include "gen.h"

int my_nb_len(int nb)
{
    int len = 1;

    nb /= 10;
    while (nb) {
        len++;
        nb /= 10;
    }
    return len;
}

int my_get_nbr(char const *str)
{
    int result = 0;

    while (*str >= '0' && *str <= '9') {
        result *= 10;
        result += *str - '0';
        str++;
    }
    return result;
}

char *number_to_str(int nb)
{
    char *result;
    int temp = nb / 10;
    int len = 1;

    while (temp) {
        len++;
        temp /= 10;
    }
    result = malloc(sizeof(char) * len);

    for (int i = len - 1; i >= 0; i--) {
        result[i] = nb % 10 + '0';
        nb /= 10;
    }
    return result;
}
