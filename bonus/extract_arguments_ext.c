/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** extract paramters
*/

#include "102architect.h"

static void fill_matrix(matrix_3_3_t *mtx, double a, double b)
{
    if (mtx->type == 't')
        translation(mtx, a, b);
    if (mtx->type == 'z')
        scaling(mtx, a, b);
    if (mtx->type == 'r')
        rotation(mtx, a);
    if (mtx->type == 's')
        reflection(mtx, a);
}

int get_arguments(int idx, int ac, char **av, matrix_3_3_t *mtx)
{
    double a = 0;
    double b = 0;
    int ret = 0;

    init_matrix(mtx);
    if (mtx->type == 't' || mtx->type == 'z') {
        if (idx == ac - 1 || !is_number(av[idx]) || !is_number(av[idx + 1]))
            return 0;
        a = my_get_double(av[idx]);
        b = my_get_double(av[idx + 1]);
        ret = 2;
    } else if (mtx->type == 'r' || mtx->type == 's') {
        if (!is_number(av[idx]))
            return 0;
        a = my_get_double(av[idx]);
        ret = 1;
    }
    fill_matrix(mtx, a, b);
    return ret;
}
