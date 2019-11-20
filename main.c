/*
** EPITECH PROJECT, 2019
** 102architech_2019
** File description:
** main
*/

int main(int ac, char **av)
{
    double point[3] = {0, 0, 0};

    if (ac >= 5) {
        point[0] = my_get_double(av[1]);
        point[1] = my_get_double(av[2]);
        
    }
    return 0;
}
