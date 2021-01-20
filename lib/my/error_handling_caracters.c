/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** error_handling caracters
*/

#include <stddef.h>
#include "my.h"

int error_handling_size_file(char *boat_position)
{
    if (boat_position[31] != '\0')
        return -1;
    if (my_strlen(boat_position) != 31)
        return -1;
}

int error_handling_map_caracters(char *boat_position)
{
    int count = 0;
    int j = 2;
    for (int i = 0; boat_position[i]; i++) {
        if (boat_position[i] == ':')
            count += 1;
    }
    if (count != 8)
        return -1;
    count = 0;
    for (int i = 0; boat_position[i]; i++) {
        if (boat_position[i] == '\n')
            count += 1;
    }
    if (count != 3)
        return -1;
    return 1;
}

int check_caracters(char **position)
{
    int j = 2;
    for (int i = 0; position[i] != NULL; i++, j++) {
        if (position[i][0] != j + '0')
            return -1;
        if (position[i][2] > 'H' || position[i][2] < 'A')
            return -1;
        if (position[i][3] > '8' || position[i][2] < '1')
            return -1;
        if (position[i][5] > 'H' || position[i][2] < 'A')
            return -1;
        if (position[i][6] > '8' || position[i][2] < '1')
            return -1;
    }
    return 1;
}

int check_line_size(char *boat_position)
{
    int count = 0;
    for (int i = 0; boat_position[i] != '\0'; i++) {
        if (boat_position[i] != '\n' || boat_position[i] != '\0') {
            count += 1;
        } else if (count != 7) {
            return -1;
        } else {
            count = 0;
        }
    }
    return 1;
}