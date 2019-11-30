/*
** EPITECH PROJECT, 2019
** csfml_2019
** File description:
** run
*/

#include "header.h"

static void display_points(window_t *w, double *point, double *point_res)
{
    sfVector2i pos_point;

    pos_point.x = point[0] * 20 + w->fb->width / 2;
    pos_point.y = point[1] * (-20) + w->fb->height / 2;
    draw_circle2(w->fb, &pos_point, 5, &sfBlue);
    pos_point.x = point_res[0] * 20 + w->fb->width / 2;
    pos_point.y = point_res[1] * (-20) + w->fb->height / 2;
    draw_circle2(w->fb, &pos_point, 5, &sfRed);
}

static void draw_line_points(framebuffer_t *fb, double **points,
double **points_res)
{
    sfVector2i pointa;
    sfVector2i pointb;
    sfVector2i pointa_res;
    sfVector2i pointb_res;

    pointa.x = points[0][0] * 20 + fb->width / 2;
    pointa.y = points[0][1] * (-20) + fb->height / 2;
    pointb.x = points[1][0] * 20 + fb->width / 2;
    pointb.y = points[1][1] * (-20) + fb->height / 2;
    pointa_res.x = points_res[0][0] * 20 + fb->width / 2;
    pointa_res.y = points_res[0][1] * (-20) + fb->height / 2;
    pointb_res.x = points_res[1][0] * 20 + fb->width / 2;
    pointb_res.y = points_res[1][1] * (-20) + fb->height / 2;
    draw_line(fb, &pointa, &pointa_res, &sfBlue);
    draw_line(fb, &pointb, &pointb_res, &sfBlue);
    draw_line(fb, &pointa, &pointb, &sfBlack);
    draw_line(fb, &pointa_res, &pointb_res, &sfBlack);
}

static int display(window_t *w, double **points, double **points_res)
{
    draw_bg(w);
    draw_line_points(w->fb, points, points_res);
    display_points(w, points[0], points_res[0]);
    display_points(w, points[1], points_res[1]);
    display_framebuffer(w->fb, w->window);
    return 0;
}

static void event_manager(window_t *w, sfEvent *e)
{
    if (e->type == sfEvtClosed)
        sfRenderWindow_close(w->window);
}

int run(double *pointa, double *pointa_res, double *pointb, double *pointb_res)
{
    sfEvent event;
    window_t *w = create_window();
    double *points[2] = {pointa, pointb};
    double *points_res[2] = {pointa_res, pointb_res};

    if (!w)
        return -1;
    display(w, points, points_res);
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event);
    }
    destroy_window(w);
    return 0;
}
