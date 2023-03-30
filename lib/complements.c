/*
** EPITECH PROJECT, 2023
** B_MUL
** File description:
** complements.c
*/

#include "../include/my.h"

int test_game_ends(data * data)
{
    if (data->plane == NULL)
        return 1;
    return 0;
}

void change_text_color(int fps, sfText * text)
{
    if (fps < 20)
        sfText_setColor(text, sfRed);
    if (fps >= 20 && fps < 40)
        sfText_setColor(text, sfColor_fromRGB(255, 128, 0));
    if (fps >= 40)
        sfText_setColor(text, sfGreen);
}

void display_fps(data * data, sfRenderWindow * window)
{
    static int first = 1;
    static sfClock * clock ;
    static int fps = 0;
    if ( first == 1) {
        clock = sfClock_create () ;
        first = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime ( clock ) ;
    float seconds = (float)elapsed.microseconds / 1000000.0f;
    if ( seconds >= 1) {
        char * fps_str = get_number(fps);
        char * str = concat_str(fps_str, " FPS");
        change_text_color(fps, data->game_data->fps_text);
        sfText_setString(data->game_data->fps_text, str);
        fps = 0;
        sfClock_restart ( clock ) ;
    } else {
        fps ++;
    }
    sfRenderWindow_drawText(window, data->game_data->fps_text, NULL);
}

void display_timer(data * data, sfRenderWindow * window)
{
    sfTime time = sfClock_getElapsedTime(data->game_data->clock);
    float seconds = (float)time.microseconds / 1000000.0f;
    char * time_str = get_number((int)seconds);
    char * str = concat_str("Timer: ", time_str);

    sfText_setString(data->game_data->timer_text, str);
    sfRenderWindow_drawText(window, data->game_data->timer_text, NULL);
}

void print_progression(int nb_elem, int i)
{
    float temp = (float)i / (float)nb_elem;
    int sec_temp = (int)(temp * 100);
    char * nb = get_number(sec_temp);
    char * percentage = concat_str(nb, "%");
    static int first = 1;
    static sfClock * clock ;

    if ( first == 1) {
        clock = sfClock_create () ;
        first = 0;
    }
    sfTime elapsed = sfClock_getElapsedTime ( clock ) ;
    float seconds = (float)elapsed.microseconds / 1000000.0f;

    if ( seconds >= 0.2f) {
        my_putstr(percentage);
        my_putstr("\n");
        sfClock_restart ( clock ) ;
    }
}
