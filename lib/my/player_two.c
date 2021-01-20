/*
** EPITECH PROJECT, 2020
** NAVY
** File description:
** player_two
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include <signal.h>
#include <string.h>
#include <stdlib.h>

int initialization_connexion_player2(int pid, char *filepath)
{
    struct sigaction sig = {0};
    if ((NAVY.bin_coord = malloc(sizeof(char))) == NULL)
        return 84;
    NAVY.bin_coord[0] = '\0';
    if (create_map(filepath) == 84) {
        my_puterr("ERROR\n");
        return 84;
    }
    NAVY.player_pid = pid;
    NAVY.enemy_life = 14;
    NAVY.life = 14;
    sig.sa_sigaction = connexion_player_two;
    sig.sa_flags = SA_SIGINFO;
    kill(NAVY.player_pid, SIGUSR1);
    my_putstr("my_pid:  ");
    my_putnbr(getpid());
    sigaction(SIGUSR1, &sig, NULL);
    pause();
}

int player_two(int pid, char *filepath)
{
    char *coord = NULL;
    if (initialization_connexion_player2(pid, filepath) == 84)
        return 84;
    while (1) {
        print_maps();
        if (receive_attack() == 1)
            return 1;
        if ((attack(coord)) == 0)
            return 0;
        if (check_hit_miss() == 0)
            return 0;
    }
}