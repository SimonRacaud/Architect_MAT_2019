/*
** EPITECH PROJECT, 2019
** 102architech_2019
** File description:
** main
*/

#include "102architect.h"

void usage(void)
{
    my_putstr("USAGE\n\t./102architect x y transfo1 arg11 [arg12] [transfo2 ");
    my_putstr("arg12 [arg22]] ...\n\nDESCRIPTION\n\tx   abscissa of the ");
    my_putstr("original point\n\ty   ordinate of the original point\n\n");
    my_putstr("\ttransfo arg1 [arg2]\n\t-t i j  translation along vector ");
    my_putstr("(i, j)\n\t-z m n  scaling by factors m (x-axis) and n (y-axis");
    my_putstr(")\n\t-r d    rotation centered in O by a d degree angle\n\t");
    my_putstr("-s d    reflection over the axis passing through O with an ");
    my_putstr("inclination\n\t\tangle of d degrees\n");
}

int is_number(char *str)
{
    int len = my_strlen(str);
    char error = 0;
    int dot = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9')
            error++;
        if (str[i] == '.' && dot == 0) {
            dot++;
            error--;
        }
        if (i == 0 && str[i] == '-')
            error--;
        if (error)
            return 0;
    }
    return 1;
}

int architect(int ac, char **av, matrix_3_3_t *operations, matrix_3_3_t *final)
{
    double point[3] = {0, 0, 0};
    double *point_res;
    int len = 0;

    point[0] = my_get_double(av[1]);
    point[1] = my_get_double(av[2]);
    operations = extract(ac - 3, av + 3, &len);
    if (!is_number(av[1]) || !is_number(av[2]) || operations == 0) {
        my_putstr(ERR_ARG);
        return 84;
    }
    if (len > 1)
        final = compute_matrix(operations, len);
    else
        final = operations;
    point_res = find_point_new_coo(final, point);
    display_transformation(av, ac);
    display_result(final, point, point_res);
    free(point_res);
    return 0;
}

int main(int ac, char **av)
{
    matrix_3_3_t *operations = NULL;
    matrix_3_3_t *final = NULL;

    if (ac >= 5) {
        architect(ac, av, operations, final);
        free(operations);
        free(final);
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        usage();
    } else {
        my_putstr(ERR_ARG);
        return 84;
    }
    return 0;
}
