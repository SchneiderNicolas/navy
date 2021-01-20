/*
** EPITECH PROJECT, 2020
** navy
** File description:
** kill it
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "include/my.h"
#include "include/struct.h"
#include <signal.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1 || argc > 3)
        return 84;
    if (my_strcmp(argv[1], "-h") == 1) {
        desc();
        return (0);
    }
    else if (argc == 2)
        return (player_one(argv[1]));
    if (argc == 3)
        return (player_two(my_getnbr(argv[1]), argv[2]));
}