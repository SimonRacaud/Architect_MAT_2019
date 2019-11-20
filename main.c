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

int main(int ac, char **av)
{
    double point[3] = {0, 0, 0};
    int len = 0;
    matrix_3_3_t *operations;

    if (ac >= 5) {
        if (!is_number(av[1]) || !is_number(av[2])) {
            my_putstr(ERR_ARG);
            return 84;
        }
        point[0] = my_get_double(av[1]);
        point[1] = my_get_double(av[2]);
        operations = extract(ac - 3, av + 3, &len);
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        usage();
    } else {
        my_putstr(ERR_ARG);
        return 84;
    }
    return 0;
}
