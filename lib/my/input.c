/*
** EPITECH PROJECT, 2020
** navy
** File description:
** input
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_realloc_str(char *str, char c)
{
    char *tmp = NULL;
    int size = my_strlen(str);

    tmp = malloc(sizeof(char) * (size + 2));
    if (str != NULL) {
        for (int i = 0; str[i]; i++)
            tmp[i] = str[i];
    }
    tmp[size] = c;
    tmp[size + 1] = '\0';
    free (str);
    return tmp;
}

char *input(void)
{
    char *buffer = NULL;
    char c = 0;
    int readfile;

    while (1) {
        readfile = read(0, &c, 1);
        if (readfile <= 0)
            return NULL;
        if (c == '\n')
            return buffer;
        buffer = my_realloc_str(buffer, c);
    }
}