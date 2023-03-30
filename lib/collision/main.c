/*
** EPITECH PROJECT, 2022
** B_MUL
** File description:
** main.c
*/

#include "collision.h"

int do_actions_bis(char const *str, va_list ap)
{
    if ((str[0] == 'r' || str[0] == 'c') && (str[1] == 'r' || str[1] == 'c')
        && str[0] != str[1]) {
        sfRectangleShape *sqr;
        sfCircleShape *cr;
        if (str[0] == 'r') {
            sqr = va_arg(ap, sfRectangleShape *);
            cr = va_arg(ap, sfCircleShape *);
        } else {
            cr = va_arg(ap, sfCircleShape *);
            sqr = va_arg(ap, sfRectangleShape *);
        }
        va_end(ap);
        return square_and_circle(sqr, cr);
    }
    va_end(ap);
    return 0;
}

int do_actions(char const *str, va_list ap)
{
    if (str[0] == 'r' && str[1] == 'r') {
        sfRectangleShape *r1 = va_arg(ap, sfRectangleShape *);
        sfRectangleShape *r2 = va_arg(ap, sfRectangleShape *);
        va_end(ap);
        return square_collision(r1, r2);
    }
    return do_actions_bis(str, ap);
}

int collision(const char *format, ...)
{
    va_list ap;

    if (*format == '\0')
        return 0;
    va_start(ap, format);
    return do_actions(format, ap);
}
