/*
** EPITECH PROJECT, 2019
** my_sreensaver_2019
** File description:
** create window
*/

#include "header.h"

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

static void draw_horizontal_lines(window_t *w)
{
    sfVector2i pt_a;
    sfVector2i pt_b;
    sfColor grey = sfColor_fromRGBA(200, 200, 200, 255);

    pt_a.y = 0;
    pt_b.y = w->fb->height;
    for (int i = 1; i < 40; i++) {
        pt_a.x = 20 * i;
        pt_b.x = 20 * i;
        if (i != 20)
            draw_line(w->fb, &pt_a, &pt_b, &grey);
        else
            draw_line(w->fb, &pt_a, &pt_b, &sfRed);
    }
}

static void draw_vertical_lines(window_t *w)
{
    sfVector2i pt_a;
    sfVector2i pt_b;
    sfColor grey = sfColor_fromRGBA(200, 200, 200, 255);

    pt_a.x = 0;
    pt_b.x = w->fb->width;
    for (int i = 1; i < 30; i++) {
        pt_a.y = 20 * i;
        pt_b.y = 20 * i;
        if (i != 15)
            draw_line(w->fb, &pt_a, &pt_b, &grey);
        else
            draw_line(w->fb, &pt_a, &pt_b, &sfRed);
    }
}

void draw_bg(window_t *w)
{
    for (unsigned int i = 0; i < w->fb->height; i++)
        for (unsigned int j = 0; j < w->fb->width; j++)
            put_pixel(w->fb, j, i, &sfWhite);
    draw_horizontal_lines(w);
    draw_vertical_lines(w);
}
