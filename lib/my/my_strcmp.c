/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my_strcmp
*/

int my_strcmp(char *str1, char *str2)
{
    int i = 0;
    for (; str1[i] == str2[i] && str1[i] != '\0'; i++);
    if (str1[i] == '\0' && str2[i] == '\0')
        return 1;
    else
        return -1;
}