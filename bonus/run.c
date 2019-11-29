/*
** EPITECH PROJECT, 2019
** csfml_2019
** File description:
** run
*/

#include "header.h"

static void draw_horizontal_lines(window_t *w)
{
    sfVector2i pt_a;
    sfVector2i pt_b;
    sfColor grey = sfColor_fromRGBA(200, 200, 200, 255);

    pt_a.y = 0;
    pt_b.y = w->fb->height;
    for(int i = 1; i < 40; i++) {
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

void display_points(window_t *w, double *point, double *point_res)
{
    sfVector2i pos_point;

    pos_point.x = point[0] * 20 + w->fb->width / 2;
    pos_point.y = point[1] * (-20) + w->fb->height / 2;
    draw_circle2(w->fb, &pos_point, 5, &sfBlue);
    pos_point.x = point_res[0] * 20 + w->fb->width / 2;
    pos_point.y = point_res[1] * (-20) + w->fb->height / 2;
    draw_circle2(w->fb, &pos_point, 5, &sfRed);
}

int display(window_t *w, double *point, double *point_res)
{
    display_points(w, point, point_res);
    display_framebuffer(w->fb, w->window);
    return 0;
}

static void event_manager(window_t *w, sfEvent *e)
{
    if (e->type == sfEvtClosed)
        sfRenderWindow_close(w->window);
}

void draw_bg(window_t *w)
{
    for(unsigned int i = 0; i < w->fb->height; i++)
        for (unsigned int j = 0; j < w->fb->width; j++)
            put_pixel(w->fb, j, i, &sfWhite);
    draw_horizontal_lines(w);
    draw_vertical_lines(w);
}

int run(double *point, double *point_res)
{
    sfEvent event;
    window_t *w = create_window();
    //sfVector2u points[3];

    if (!w)
        return -1;
    draw_bg(w);
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event);
        display(w, point, point_res);
    }
    destroy_window(w);
    return 0;
}
