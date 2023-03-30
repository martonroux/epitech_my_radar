/*
** EPITECH PROJECT, 2022
** B_MUL
** File description:
** my_get_nbr.c
*/

#include "../include/my.h"

void my_putstr(char const *str)
{
    while (*str) {
        write(1, &*str, 1);
        str++;
    }
}

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int *my_get_nbr(char *str)
{
    int number = 0;
    int nb_len = 0;
    while (*str) {
        while (*str >= '0' && *str <= '9') {
            number *= 10;
            number += *str - '0';
            nb_len++;
            str++;
        }
        if (number != 0)
            break;
        str++;
    }
    int *result = malloc(sizeof(int) * 2);
    result[0] = number;
    result[1] = nb_len;
    return result;
}

char * get_number(int nb)
{
    int nb_len = 0;
    int temp = nb;
    for (; temp > 0; nb_len++)
        temp /= 10;
    if (nb == 0)
        nb_len = 1;
    char *res = malloc(sizeof(char) * (nb_len + 1));

    res[nb_len] = '\0';
    for (; nb_len > 0; nb_len--) {
        res[nb_len - 1] = nb % 10 + '0';
        nb /= 10;
    }
    return res;
}

int my_strlen(char const * str)
{
    int len = 0;

    for (; str[len]; len++);
    return len;
}
