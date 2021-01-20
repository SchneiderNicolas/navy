/*
** EPITECH PROJECT, 2020
** dante
** File description:
** my_getnumber
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int neg = 1;
    int i = 0;

    for (; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            neg *= -1;
    }
    for (; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - '0';
        } else {
            return (nb * neg);
        }
    }
    return (nb * neg);
}