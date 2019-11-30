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
    framebuffer_t *fb;
} window_t;

window_t *create_window(void);
void destroy_window(window_t *w);

void draw_bg(window_t *w);

#endif
