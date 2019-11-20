/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** Display the result
*/

#include "102architect.h"

void display_transformation(char **av, int ac)
{
    for (int i = 3; i < ac) {
        if (my_strcmp(av[i], "-t") == 0) {
            my_printf("Translation along vector ");
            my_printf("(%s, %s)\n", av[i + 1], av[i + 2]);
            i += 2;
        } else if (my_strcmp(av[i], "-z") == 0) {
            my_printf("Scaling by factors %s and %s\n", av[i + 1], av[i + 2]);
            i += 2;
        }
        if (my_strcmp(av[i], "-r") == 0) {
            my_printf("Rotation by a %s degree angle\n", av[i + 1]);
            i++;
        } else if (my_strcmp(av[i], "-s") == 0) {
            my_printf("Reflection over an axis with an inclination");
            my_printf(" angle of %s degrees\n", av[i + 1]);
            i += 2;
        }
    }
}

void display_result(matrix_3_3_t matrix_res, double *point_coo,
double *point_new_coo)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            my_put_double(matrix_res->matrix[i][j]);
            my_putstr("\t");
        }
    my_putstr("(");
    my_put_double(point_coo[0]);
    my_putstr(", ");
    my_put_double(point_coo[1]);
    my_putstr(") => (");
    my_put_double(point_new_coo[0]);
    my_putstr(", ");
    my_put_double(point_new_coo[1]);
    my_putstr(")\n");
}
