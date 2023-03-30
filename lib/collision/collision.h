/*
** EPITECH PROJECT, 2022
** B_MUL
** File description:
** collision.h
*/

#pragma once

#include <stdarg.h>
#include "../../include/my.h"

int square_and_circle(sfRectangleShape *sqr, sfCircleShape *cr);
int square_collision(sfRectangleShape *sqr1, sfRectangleShape *sqr2);
