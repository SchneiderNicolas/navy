/*
** EPITECH PROJECT, 2020
** dante
** File description:
** my_strlen
*/

#include "my.h"
#include <stddef.h>

unsigned int my_strlen(char const *str)
{
    unsigned int count = 0;
    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        count += 1;
    return (count);
}