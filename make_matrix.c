/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** create matrix
*/

#include "102architect.h"

void translation(matrix_3_3_t *mtx, double i, double j)
{
    mtx->matrix[0][2] = i;
    mtx->matrix[1][2] =	j;
}

void scaling(matrix_3_3_t *mtx, double m, double n)
{
    mtx->matrix[0][0] =	m;
    mtx->matrix[1][1] =	n;
}

void rotation(matrix_3_3_t *mtx, double angle)
{
    mtx->matrix[0][0] = cos(angle * PI / 180) * 180 / PI;
    mtx->matrix[0][1] = -sin(angle * PI / 180) * 180 / PI;
    mtx->matrix[1][0] = sin(angle * PI / 180) * 180 / PI;
    mtx->matrix[1][1] = cos(angle * PI / 180) * 180 / PI;
}

void reflection(matrix_3_3_t *mtx, double angle)
{
    mtx->matrix[0][0] = cos(2 * angle * PI / 180) * 180 / PI;
    mtx->matrix[0][1] = sin(2 * angle * PI / 180) * 180 / PI;
    mtx->matrix[1][0] = sin(2 * angle * PI / 180) * 180 / PI;
    mtx->matrix[1][1] = -cos(2 * angle * PI / 180) * 180 / PI;
}
