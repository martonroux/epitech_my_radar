/*
** EPITECH PROJECT, 2022
** B_MUL
** File description:
** gen.h
*/

#pragma once

#define WINDOW_HEIGHT 1080
#define WINDOW_WIDTH 1920
#define SPEED_MAX_PLANE 50
#define DELAY_MAX_PLANE 5
#define RADIUS_MAX_TOWER 30

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int my_get_nbr(char const *str);
char *number_to_str(int nb);
int error_gest(int argc, char **argv);
int my_nb_len(int nb);
