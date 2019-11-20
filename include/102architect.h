/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** Header for 102architect
*/

#ifndef ARCHITECT_H
#define ARCHITECT_H

#define ERR_ARG "ERROR: a parameter is not a number\n"

#include "my.h"

typedef struct matrix_3_3 {
    double matrix[3][3];
    char type;
} matrix_3_3_t;

double my_get_double(char *nbr);

int is_number(char *str);
matrix_3_3_t *extract(int ac, char **av, int *len);

void translation(matrix_3_3_t *mtx, double i, double j);
void scaling(matrix_3_3_t *mtx, double m, double n);
void rotation(matrix_3_3_t *mtx, double angle);
void reflection(matrix_3_3_t *mtx, double angle);

#endif
