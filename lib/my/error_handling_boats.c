/*
** EPITECH PROJECT, 2020
** navy
** File description:
** error_handling_boats
*/

#include <stddef.h>
#include "my.h"

int check_boat_possible(char **position)
{
    for (int i = 0; position[i] != NULL; i++) {
        if (!(position[i][2] == position[i][5] ||
        position[i][3] == position[i][6])) {
            return -1;
        }
    }
    return 1;
}

int check_boat_lenght(char **position)
{
    int j = 1;
    for (int i = 0; position[i] != NULL; i++, j++) {
        if (position[i][2] != position[i][5] &&
        position[i][5] - position[i][2] != j)
            return -1;
        else if (position[i][3] != position[i][6] &&
        position[i][6] - position[i][3] != j)
            return -1;
    }
    return 1;
}