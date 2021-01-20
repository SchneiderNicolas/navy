/*
** EPITECH PROJECT, 2020
** navy
** File description:
** connexion
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void connexion_player_one(int signum, siginfo_t *siginfo, void *oldact)
{
    my_putstr("enemy connected\n");
    NAVY.player_pid = siginfo->si_pid;
    usleep(10000);
    kill(NAVY.player_pid, SIGUSR1);
}

void connexion_player_two(int signum, siginfo_t *siginfo, void *oldact)
{
    my_putstr("\nsuccessfully connected\n");
}
