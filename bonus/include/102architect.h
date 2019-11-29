/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** Header for 102architect
*/

#ifndef ARCHITECT_H
#define ARCHITECT_H

#define ERR_ARG_NBR "ERROR: a parameter is not a number\n"
#define ERR_ARG "ERROR: invalid argument\n"
#define PI 3.14159265

#include "my.h"
#include <stdlib.h>
#include <math.h>

typedef struct matrix_3_3 {
    double matrix[3][3];
    char type;
} matrix_3_3_t;

double my_get_double(char *nbr);

int is_number(char *str);
matrix_3_3_t *extract(int ac, char **av, int *len);
int get_arguments(int idx, int ac, char **av, matrix_3_3_t *mtx);
void init_matrix(matrix_3_3_t *mtx);

void translation(matrix_3_3_t *mtx, double i, double j);
void scaling(matrix_3_3_t *mtx, double m, double n);
void rotation(matrix_3_3_t *mtx, double angle);
void reflection(matrix_3_3_t *mtx, double angle);

void display_transformation(char **av, int ac);
void display_result(matrix_3_3_t *matrix_res, double *point_coo,
double *point_new_coo);

matrix_3_3_t *compute_matrix(matrix_3_3_t *matrix, int nb_matrix);
double *find_point_new_coo(matrix_3_3_t *matrix_res, double *point_coo);

int run(double *point, double *point_res);

#endif
