/*
** EPITECH PROJECT, 2020
** NAVY
** File description:
** Player one
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include <signal.h>
#include <string.h>
#include <stdlib.h>

int initialization_connexion_player1(char *filepath)
{
    if ((NAVY.bin_coord = malloc(sizeof(char))) == NULL)
        return 84;
    NAVY.bin_coord[0] = '\0';
    if (create_map(filepath) == 84) {
        my_puterr("ERROR");
        return 84;
    }
    NAVY.enemy_life = 14;
    NAVY.life = 14;
    struct sigaction sig = {0};
    sig.sa_sigaction = connexion_player_one;
    sig.sa_flags = SA_SIGINFO;
    my_putstr("my_pid:  ");
    my_putnbr(getpid());
    my_putstr("\nwaiting for enemy connexion...\n\n");
    sigaction(SIGUSR1, &sig, NULL);
    pause();
}

int player_one(char *filepath)
{
    char *coord = NULL;
    if ((initialization_connexion_player1(filepath)) == 84)
        return 84;
    while (1){
        print_maps();
        if ((attack(coord)) == 0)
            return 0;
        if (check_hit_miss() == 0)
            return 0;
        if (receive_attack() == 1)
            return 1;
    }
}