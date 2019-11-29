/*
** EPITECH PROJECT, 2019
** CPool_Day09_2019
** File description:
** Task02 - Headers of libmy
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <math.h>

#define POW(x, y) my_compute_power_rec(x, y)
//#define ABS(x) (x < 0) ? -x : x

int my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(long long int nb);
int my_put_nbr_ul(unsigned long long int nb);
int my_putnbr_base(long int nbr, char const *base);
void my_put_double(double nb, int nb_decimal);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *str);
char *convert_base(char const *nbr, char const *base_from, char const *base_to);
char **my_str_to_word_array(char const *str);
int my_show_word_array(char * const *tab);
int my_getnbr_base(char const *str, char const *base);
char *my_putnbr_base_s(int nbr, char const *base);
void my_putstr_error(char *str);
int my_printf(char *format, ...);

#endif /* MY_H_ */