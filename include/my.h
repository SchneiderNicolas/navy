/*
** EPITECH PROJECT, 2020
** dante
** File description:
** my.h
*/

#include "struct.h"
#include <stdio.h>
#include <sys/types.h>
#include "struct.h"
#include <signal.h>
#include <string.h>
#include <stdlib.h>

#ifndef MY_H
    #define MY_H

unsigned int my_strlen(char const *str);
void desc(void);
void my_putstr(char const *str);
void my_putchar(char c);
void my_putnbr(long long int nb);
void my_puterr(char const *str);
int my_getnbr(char const *str);
char *my_strcat(char *str1, char *str2);
char *fs_cat_x_bytes(char const *filepath, int size);
int count_words(char *str, char separator);
char *count_letters(int *letters, char *str, char separator);
char **my_str_to_word_array(char *str, char separator);
char *input(void);
int my_strcmp(char *str1, char *str2);
int error_handling_size_file(char *boat_position);
int error_handling_map_caracters(char *boat_position);
int check_caracters(char **position);
int check_line_size(char *boat_position);
int check_boat_possible(char **position);
int check_boat_lenght(char **position);
void add_boat2(char **map_with_boat, char **position);
void add_boat3(char **map_with_boat, char **position);
void add_boat4(char **map_with_boat, char **position);
void add_boat5(char **map_with_boat, char **position);
int add_boats_and_check(char **map_with_boat, char **position);
char **create_empty_map(void);
int create_map(char *filepath);
void print_my_positions(void);
void print_enemy_position(void);
char *nb_to_binary(int nb);
int send_attack_coord(char *coord);
char *bin_to_coord(char *bin);
int check_coord(char *coord);
void connexion_player_one(int signum, siginfo_t *siginfo, void *oldact);
void connexion_player_two(int signum, siginfo_t *siginfo, void *oldact);
char *receive_attack_coord(void);
void catch_bin(int signum);
int check_if_hit(char *coord);
void send_miss(void);
void send_hit(void);
void hit_miss(int signum);
void receive_hit_miss(void);
void print_maps(void);
int attack(char *coord);
int receive_attack(void);
int check_hit_miss(void);
int initialization_connexion_player1(char *filepath);
int player_one(char *filepath);
int initialization_connexion_player2(int pid, char *filepath);
int player_two(int pid, char *filepath);

#endif