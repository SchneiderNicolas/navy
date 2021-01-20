/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** receive hit or miss
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void hit_miss(int signum)
{
    if (signum == 10) {
        NAVY.enemy_life -= 1;
        NAVY.enemy_position[NAVY.coord[1] - '1'][NAVY.coord[0] - 'A'] = 'x';
        NAVY.hit_miss = 1;
    }
    if (signum == 12) {
        if (!(NAVY.enemy_position[NAVY.coord[1] - '1'][NAVY.coord[0] - 'A']
        == 'x'))
            NAVY.enemy_position[NAVY.coord[1] - '1'][NAVY.coord[0] - 'A'] = 'o';
        NAVY.hit_miss = 0;
    }
}

void receive_hit_miss(void)
{
    signal(SIGUSR1, hit_miss);
    signal(SIGUSR2, hit_miss);
    pause();
}

int check_hit_miss(void)
{
    receive_hit_miss();
    if (NAVY.hit_miss == 1) {
        my_putstr(NAVY.coord);
        my_putstr(":  hit\n");
    }
    if (NAVY.hit_miss == 0) {
        my_putstr(NAVY.coord);
        my_putstr(":  missed\n");
    }
    free(NAVY.coord);
    if ((NAVY.bin_coord = malloc(sizeof(char))) == NULL)
        return 84;
    NAVY.bin_coord[0] = '\0';
    if (NAVY.enemy_life <= 0) {
        print_my_positions();
        print_enemy_position();
        my_putstr("\nI won\n\n");
        return 0;
    }
}