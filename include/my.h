/*
** EPITECH PROJECT, 2023
** github_test
** File description:
** my.h
*/

#pragma once

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define MAX_PLANE_HITBOX_SIZE 40

#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Export.h>

typedef struct plane_t plane;

typedef struct tower_t {
    sfSprite * sprite;
    sfCircleShape * area;
    sfVector2f pos;
    int radius;
} tower;

typedef struct plane_data_t {
    sfSprite * sprite;
    sfRectangleShape * area;
    sfVector2f origin;
    sfVector2f dest;
    int speed;
    int delay;
    int destroy_plane;
    float size;
} plane_data;

typedef struct quarantine_t {
    plane_data ** data;
    int nb_planes;
} quarantine;

struct plane_t {
    plane * next;
    plane * previous;
    plane_data * data;
};

typedef struct areas_t {
    sfIntRect rect;
    sfRectangleShape * area;
} areas;

typedef struct window_t {
    sfRenderWindow *window;
    sfEvent event;
} window;

typedef struct game_data_t {
    sfText * timer_text;
    sfText * fps_text;
    sfText * planes_text;
    sfClock * clock;
    int nb_areas;
    int nb_towers;
    int key_pressed;
    int show_areas;
    int show_elems;
    float game_speed;
    int nb_planes;
} game_data;

typedef struct data_t {
    plane * plane;
    areas * areas;
    quarantine ** quarantine;
    tower ** towers;
    window window;
    game_data * game_data;
} data;

plane * ll_create(plane_data *data);
void ll_add(plane_data * value, data * data);
void ll_delete(plane * plane, data * data);

void my_putstr(char const *str);
int * my_get_nbr(char *str);
int ** parsing(char *filename);
void render(data *data);
plane_data * init_plane(int * numbers);
tower ** init_towers(int ** numbers, int nb_towers);
window init_window(void);
areas * init_area(int nb_areas);
data * init_data(int nb_areas, int ** numbers);
quarantine ** init_quarantine(int nb_areas, int nb_planes);
game_data * init_game_data(int nb_areas, int nb_towers, int nb_planes);
int my_sfintrect_col(sfIntRect *rect, int x, int y, int size);
void check_area(data * data);
int collision(const char *format, ...);
void check_collision(data *data);
void move_planes(data *data);
void key_pressing(data * data);
int test_game_ends(data * data);
void display_timer(data * data, sfRenderWindow * window);
int error_gest(int argc, char ** argv);
int is_num(char c);
void display_fps(data * data, sfRenderWindow * window);
char * get_number(int nb);
int my_strlen(char const * str);
char * concat_str(char * str_1, char * str_2);
void print_progression(int nb_elem, int i);
int check_out_of_screen(plane * plane);
void display_nb_planes(data * data, sfRenderWindow * window);
