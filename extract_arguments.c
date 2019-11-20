/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** extract paramters
*/

#include "102architect.h"

static int count_minus(int ac, char **av)
{
    int len = 0;

    for (int i = 0; i < ac; i++) {
        if (av[i][0] == '-')
            len++;
    }
    return len;
}

static char get_type(char *str)
{
    if (str[0] != '-')
        return 0;
    if (str[1] == 't' && str[2] == '\0')
        return 't';
    if (str[1] == 'z' && str[2] == '\0')
        return 'z';
    if (str[1] == 'r' && str[2] == '\0')
        return 'r';
    if (str[1] == 's' && str[2] == '\0')
        return 's';
    return 0;
}

void init_matrix(matrix_3_3_t *mtx)
{
    mtx->matrix[0][0] = 1;
    mtx->matrix[0][1] = 0;
    mtx->matrix[0][2] = 0;
    mtx->matrix[1][0] = 0;
    mtx->matrix[1][1] = 1;
    mtx->matrix[1][2] = 0;
    mtx->matrix[2][0] = 0;
    mtx->matrix[2][1] = 0;
    mtx->matrix[2][2] = 1;
}

matrix_3_3_t *extract(int ac, char **av, int *len)
{
    int len_array = count_minus(ac, av);
    matrix_3_3_t *matrix = malloc(sizeof(matrix_3_3_t) * len_array);
    int ret;

    if (len_array == 0)
        return NULL;
    for (int i = 0; i < ac; i++) {
        matrix[*len].type = get_type(av[i]);
        if (matrix[*len].type == 0 || i == ac - 1)
            return NULL;
        ret = get_arguments(++i, ac, av, &matrix[*len]);
        if (ret == 0)
            return NULL;
        i += ret - 1;
        (*len)++;
    }
    return matrix;
}
