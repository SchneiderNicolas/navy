/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** adding boats to empty map
*/

#include <stddef.h>
#include "my.h"

void add_boat2(char **map_with_boat, char **position)
{
    int x = position[0][3] - '0' - 1;
    int y = position[0][2] - 'A';
    if (position[0][2] == position[0][5]) {
        map_with_boat[x][y] = '2';
        map_with_boat[x + 1][y] = '2';
    } else {
        map_with_boat[x][y] = '2';
        map_with_boat[x][y + 1] = '2';
    }
}

void add_boat3(char **map_with_boat, char **position)
{
    int x = position[1][3] - '0' - 1;
    int y = position[1][2] - 'A';
    if (position[1][2] == position[1][5]) {
        map_with_boat[x][y] = '3';
        map_with_boat[x + 1][y] = '3';
        map_with_boat[x + 2][y] = '3';
    } else {
        map_with_boat[x][y] = '3';
        map_with_boat[x][y + 1] = '3';
        map_with_boat[x][y + 2] = '3';
    }
}

void add_boat4(char **map_with_boat, char **position)
{
    int x = position[2][3] - '0' - 1;
    int y = position[2][2] - 'A';
    if (position[2][2] == position[2][5]) {
        map_with_boat[x][y] = '4';
        map_with_boat[x + 1][y] = '4';
        map_with_boat[x + 2][y] = '4';
        map_with_boat[x + 3][y] = '4';
    } else {
        map_with_boat[x][y] = '4';
        map_with_boat[x][y + 1] = '4';
        map_with_boat[x][y + 2] = '4';
        map_with_boat[x][y + 3] = '4';
    }
}

void add_boat5(char **map_with_boat, char **position)
{
    int x = position[3][3] - '0' - 1;
    int y = position[3][2] - 'A';
    if (position[3][2] == position[3][5]) {
        map_with_boat[x][y] = '5';
        map_with_boat[x + 1][y] = '5';
        map_with_boat[x + 2][y] = '5';
        map_with_boat[x + 3][y] = '5';
        map_with_boat[x + 4][y] = '5';
    } else {
        map_with_boat[x][y] = '5';
        map_with_boat[x][y + 1] = '5';
        map_with_boat[x][y + 2] = '5';
        map_with_boat[x][y + 3] = '5';
        map_with_boat[x][y + 4] = '5';
    }
}

int add_boats_and_check(char **map_with_boat, char **position)
{
    int boat_count = 0;
    add_boat2(map_with_boat, position);
    add_boat3(map_with_boat, position);
    add_boat4(map_with_boat, position);
    add_boat5(map_with_boat, position);
    for (int i = 0; map_with_boat[i] != NULL; i++) {
        for (int j = 0; map_with_boat[i][j] != '\0'; j++) {
            if (map_with_boat[i][j] >= '2' && map_with_boat[i][j] <= '5') {
                boat_count += 1;
            }
        }
    }
    if (boat_count != 14) {
        return 84;
    }
    return 1;
}