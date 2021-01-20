/*
** EPITECH PROJECT, 2020
** dante
** File description:
** my_putnbr
*/

#include "my.h"
#include <unistd.h>

void my_putnbr(long long int nb)
{
    if (0 > nb) {
        my_putchar('-');
        nb *= -1;
    }
    if (10 <= nb) {
        my_putnbr(nb / 10);
    }
    my_putchar((nb % 10) + '0');
}