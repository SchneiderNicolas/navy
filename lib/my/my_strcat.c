/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

char *my_strcat(char *str1, char *str2)
{
    char *str;
    int i;
    if (str1 == NULL || str2 == NULL)
        return (NULL);
    i = my_strlen(str1) + my_strlen(str2) + 1;
    if ((str = malloc(sizeof(char) * i)) == NULL)
        return (NULL);
    i = 0;
    while (*str1 != '\0')
        str[i++] = *str1++;
    while (*str2 != '\0')
        str[i++] = *str2++;
    str[i] = '\0';
    return (str);
}