/*
** EPITECH PROJECT, 2019
** csfml_2019
** File description:
** header
*/

#ifndef H_HEADER
#define H_HEADER

#include <stdlib.h>
#include "framebuffer.h"

#define W_WIDTH 800
#define W_HEIGHT 600

typedef struct window {
    sfRenderWindow *window;
    sfColor color;
    sfVector2u p1;
    sfVector2u p2;
    sfVector2u p3;
    framebuffer_t *fb;
} window_t;

window_t *create_window(void);
void destroy_window(window_t *w);
int display(window_t *w, double *point, double *point_res);

#endif
