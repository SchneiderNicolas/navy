/*
** EPITECH PROJECT, 2019
** navy
** File description:
** fs_cat_x_bytes.c
*/

#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char *fs_cat_x_bytes(char const *filepath, int size)
{
    char *buffer;
    int fd;
    int readfile;

    if ((buffer = malloc(sizeof(char) * (size + 1))) == NULL)
        return NULL;
    if ((fd = open(filepath, O_RDONLY)) == -1)
        return NULL;
    if ((readfile = read(fd, buffer, size)) == -1)
        return NULL;
    close(fd);
    return (buffer);
}