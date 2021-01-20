/*
** EPITECH PROJECT, 2020
** NAVY
** File description:
** send if hit or miss
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void send_hit(void)
{
    NAVY.life -= 1;
    usleep(10000);
    kill(NAVY.player_pid, SIGUSR1);
}

void send_miss(void)
{
    usleep(10000);
    kill(NAVY.player_pid, SIGUSR2);
}