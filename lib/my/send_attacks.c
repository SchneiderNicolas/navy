/*
** EPITECH PROJECT, 2020
** Navy
** File description:
** send attacks
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include <signal.h>
#include <string.h>
#include <stdlib.h>

char *nb_to_binary(int nb)
{
    switch (nb)
    {
        case 1:
            return ("0001");
        case 2:
            return ("0010");
        case 3:
            return ("0011");
        case 4:
            return ("0100");
        case 5:
            return ("0101");
        case 6:
            return ("0110");
        case 7:
            return ("0111");
        case 8:
            return ("1000");
    }
}

int send_attack_coord(char *coord)
{
    int colone = coord[0] - 'A' + 1;
    int line = coord[1] - '0';
    char *to_send = my_strcat(nb_to_binary(colone), nb_to_binary(line));
    coord[2] = '\0';
    NAVY.coord = coord;
    for (int i = 0; to_send[i] != '\0'; i++) {
        usleep(10000);
        if (to_send[i] == '0')
            kill(NAVY.player_pid, SIGUSR2);
        else if (to_send[i] == '1')
            kill(NAVY.player_pid, SIGUSR1);
    }
    free(to_send);
    return 1;
}

char *bin_to_coord(char *bin)
{
    char *coord;
    int total = 0;
    if ((coord = malloc(sizeof(char) * 2 + 1)) == NULL || bin == NULL)
        return NULL;
    for (int i = 0; i < 4; i++) {
        total *= 2;
        if (bin[i] == '1')
            total += 1;
    }
    coord[0] = total + 'A' - 1;
    total = 0;
    for (int i = 4; i < 8; i++) {
        total *= 2;
        if (bin[i] == '1')
            total += 1;
    }
    coord[1] = total + '0';
    coord[2] = '\0';
    return coord;
}

int check_coord(char *coord)
{
    if (my_strlen(coord) > 2)
        return -1;
    if (coord[0] > 'H' || coord[0] < 'A')
            return -1;
    if (coord[1] > '8' || coord[1] < '1')
            return -1;
    NAVY.wrong_position = 0;
    return 1;
}

int attack(char *coord)
{
    coord = NULL;
    NAVY.wrong_position = 1;
    usleep(10000);
    while (NAVY.wrong_position == 1) {
        my_putstr("\nattack:  ");
        if ((coord = input()) == NULL)
            return 0;
        if (check_coord(coord) == -1)
            my_putstr("wrong position");
    }
    send_attack_coord(coord);
}