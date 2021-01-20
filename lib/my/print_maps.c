/*
** EPITECH PROJECT, 2020
** navy
** File description:
** print maps
*/

#include <stddef.h>
#include "my.h"
#include <stdlib.h>

void print_my_positions(void)
{
    my_putstr("\nmy positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; NAVY.my_position[i] != NULL; i++) {
        my_putnbr(i + 1);
        my_putchar('|');
        for (int j = 0; NAVY.my_position[i][j] != '\0'; j++) {
            my_putchar(NAVY.my_position[i][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
    my_putchar('\n');
}

void print_enemy_position(void)
{
    my_putstr("enemy's positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; NAVY.enemy_position[i] != NULL; i++) {
        my_putnbr(i + 1);
        my_putchar('|');
        for (int j = 0; NAVY.enemy_position[i][j] != '\0'; j++) {
            my_putchar(NAVY.enemy_position[i][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}

void print_maps(void)
{
    print_my_positions();
    print_enemy_position();
}