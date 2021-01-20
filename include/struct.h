/*
** EPITECH PROJECT, 2020
** dante
** File description:
** struct.h
*/

#ifndef STRUCT_H
#define STRUCT_H

#define NAVY navy_t

struct navy_s {
    int player_pid;
    char *coord;
    char *bin_coord;
    int hit_miss;
    char **enemy_position;
    char **my_position;
    int wrong_position;
    int enemy_life;
    int life;
} navy_t;

#endif /* !STRUCT_H */
