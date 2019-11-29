/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** create window
*/

#include "header.h"

void draw_bg()

window_t *create_window(void)
{
    window_t *w = malloc(sizeof(window_t));
    sfVideoMode mode = {W_WIDTH, W_HEIGHT, 32};

    w->window = sfRenderWindow_create(mode, "architect", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(w->window, 60);
    w->fb = framebuffer_create(W_WIDTH, W_HEIGHT);
    if (!w->window)
        return NULL;
    return w;
}

void destroy_window(window_t *w)
{
    sfRenderWindow_destroy(w->window);
    framebuffer_destroy(w->fb);
    free(w);
}
