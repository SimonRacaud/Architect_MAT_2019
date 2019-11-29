/*
** EPITECH PROJECT, 2019
** csfml_2019
** File description:
** run
*/

#include "header.h"

int display(window_t *w)
{

    return 0;
}

static void event_manager(window_t *w, sfEvent *e)
{
    if (e->type == sfEvtClosed)
        sfRenderWindow_close(w->window);
}

static void init()

int run(void)
{
    sfEvent event;
    window_t *w = create_window();
    sfVector2u points[3];

    if (!w)
        return -1;
    while (sfRenderWindow_isOpen(w->window)) {
        while (sfRenderWindow_pollEvent(w->window, &event))
            event_manager(w, &event);
        display(w);
    }
    destroy_window(w);
    return 0;
}
