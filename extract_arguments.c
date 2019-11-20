/*
** EPITECH PROJECT, 2019
** 102architect_2019
** File description:
** extract paramters
*/

#include "102architect.h"

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

matrix_3_3_t *extract(int ac, char **av, int *len)
{

}
