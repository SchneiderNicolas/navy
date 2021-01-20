/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** receive attack coord
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void catch_bin(int signum)
{
    if (signum == 10) {
        NAVY.bin_coord = my_strcat(NAVY.bin_coord, "1");
    }
    if (signum == 12) {
        NAVY.bin_coord = my_strcat(NAVY.bin_coord, "0");
    }
}

char *receive_attack_coord(void)
{
    for (int i = 0; i < 8; i++) {
        signal(SIGUSR1, catch_bin);
        signal(SIGUSR2, catch_bin);
        pause();
    }
    return (bin_to_coord(NAVY.bin_coord));
}

int check_if_hit(char *coord)
{
    if (NAVY.my_position[coord[1] - '1'][coord[0] - 'A'] == '.' ||
    NAVY.my_position[coord[1] - '1'][coord[0] - 'A'] == 'x' ||
    NAVY.my_position[coord[1] - '1'][coord[0] - 'A'] == 'o') {
        if (NAVY.my_position[coord[1] - '1'][coord[0] - 'A'] != 'x')
            NAVY.my_position[coord[1] - '1'][coord[0] - 'A'] = 'o';
        my_putchar('\n');
        my_putstr(coord);
        my_putstr(":  miss\n");
        NAVY.hit_miss = 0;
        return 0;
    } else {
        NAVY.my_position[coord[1] - '1'][coord[0] - 'A'] = 'x';
        my_putchar('\n');
        my_putstr(coord);
        my_putstr(":  hit\n");
        NAVY.hit_miss = 1;
        return 1;
    }
}

int receive_attack(void)
{
    my_putstr("\nwaiting for enemy's attack...");
    if (check_if_hit(receive_attack_coord()) == 0) {
        send_miss();
    } else {
        send_hit();
    }
    if (NAVY.life <= 0) {
        print_my_positions();
        print_enemy_position();
        my_putstr("\nI lose\n\n");
        return 1;
    }
    return 0;
}