/*
** EPITECH PROJECT, 2019
** 102architech_2019
** File description:
** main
*/

#include "102architect.h"

void usage(void)
{
    my_putstr("USAGE\n\t./102architect xa ya xb yb ");
    my_putstr("transfo1 arg11 [arg12] [transfo2 ");
    my_putstr("arg12 [arg22]] ...\n\nDESCRIPTION\n\txa, xb\tabscissa of the ");
    my_putstr("original points\n\tya, yb\tordinate of the original points\n");
    my_putstr("\n\ttransfo arg1 [arg2]\n\t-t i j  translation along vector ");
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

int architect(int ac, char **av, matrix_3_3_t *operations, matrix_3_3_t **final)
{
    double pointa[3] = {0, 0, 1};
    double pointb[3] = {0, 0, 1};
    double *pointa_res = NULL;
    double *pointb_res = NULL;
    int len = 0;

    pointa[0] = my_get_double(av[1]);
    pointa[1] = my_get_double(av[2]);
    pointb[0] = my_get_double(av[3]);
    pointb[1] = my_get_double(av[4]);
    operations = extract(ac - 5, av + 5, &len);
    if (!is_number(av[1]) || !is_number(av[2]) || !is_number(av[3]) ||
    !is_number(av[4]) || operations == NULL) {
        my_putstr(ERR_ARG);
        return 84;
    }
    if (len > 1)
        final[0] = compute_matrix(operations, len);
    else
        final[0] = operations;
    pointa_res = find_point_new_coo(final[0], pointa);
    pointb_res = find_point_new_coo(final[0], pointb);
    display_transformation(av, ac);
    display_result(final[0], pointa, pointa_res);
    display_result(final[0], pointb, pointb_res);
    run(pointa, pointa_res, pointb, pointb_res);
    free(pointa_res);
    free(pointb_res);
    return 0;
}

int main(int ac, char **av)
{
    matrix_3_3_t *operations = NULL;
    matrix_3_3_t *final = NULL;
    int val = 0;

    if (ac >= 5) {
        val = architect(ac, av, operations, &final);
        free(final);
        return val;
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        usage();
        return 0;
    } else {
        my_putstr(ERR_ARG);
        return 84;
    }
}
