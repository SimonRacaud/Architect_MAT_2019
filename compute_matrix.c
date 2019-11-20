/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** Compute square matrix
*/

#include "102architect.h"

double *find_point_new_coo(matrix_3_3_t *matrix_res, double *point_coo)
{
    double a = 0;
    double b = 0;
    double *point_new_coo = malloc(sizeof(double) * 3);

    point_new_coo[0] = 0;
    point_new_coo[1] = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            a = matrix_res->matrix[i][j];
            b = point_coo[j];
            point_new_coo[i] += a * b;
        }
    }
    return point_new_coo;
}

static void compute_two_matrix(matrix_3_3_t *matrix1,
matrix_3_3_t *matrix2, int line, matrix_3_3_t *matrix_res)
{
    double a = 0;
    double b = 0;

    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            a = matrix1->matrix[line][k];
            b = matrix2->matrix[k][j];
            matrix_res->matrix[line][j] += a * b;
        }
    }
    if (line < 2)
        compute_two_matrix(matrix1, matrix2, line + 1, matrix_res);
}

matrix_3_3_t *compute_matrix(matrix_3_3_t *matrix, int nb_matrix)
{
    matrix_3_3_t *matrix_res = malloc(sizeof(*matrix_res));

    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++)
            matrix_res->matrix[j][k] = 0;
    }
    for (int i = 0; i < nb_matrix - 1; i++)
        if (i == 0)
            compute_two_matrix(&matrix[i + 1], &matrix[i], 0, matrix_res);
        else
            compute_two_matrix(&matrix[i + 1], matrix_res, 0, matrix_res);
    return matrix_res;
}
