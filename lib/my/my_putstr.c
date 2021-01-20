/*
** EPITECH PROJECT, 2020
** dante
** File description:
** my_putstr.c
*/

#include "my.h"
#include <unistd.h>

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}