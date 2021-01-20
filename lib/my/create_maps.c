/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** create maps
*/

#include <stddef.h>
#include "my.h"
#include <stdlib.h>

char **create_empty_map(void)
{
    int i = 0;
    int j = 0;
    char **empty_map;
    if ((empty_map = malloc(sizeof(char *) * 9)) == NULL)
        return NULL;
    for (; i < 8; i++) {
        empty_map[i] = malloc(sizeof(char) * 9);
        for (; j < 8; j++) {
            empty_map[i][j] = '.';
        }
        empty_map[i][j] = '\0';
        j = 0;
    }
    empty_map[i] = NULL;
    return (empty_map);
}

int create_map(char *filepath)
{
    char *boat_position;
    char **position;
    if ((boat_position = fs_cat_x_bytes(filepath, 32)) == NULL)
        return 84;
    boat_position[31] = '\0';
    if (check_line_size(boat_position) == -1 ||
    error_handling_size_file(boat_position) == -1 ||
    error_handling_map_caracters(boat_position) == -1)
        return 84;
    position = my_str_to_word_array(boat_position, '\n');
    free(boat_position);
    if (check_caracters(position) == -1 || check_boat_lenght(position) == -1 ||
    check_boat_possible(position) == -1)
        return 84;
    NAVY.my_position = create_empty_map();
    NAVY.enemy_position = create_empty_map();
    if (add_boats_and_check(NAVY.my_position, position) == 84) {
        return 84;
    }
    return 0;
}