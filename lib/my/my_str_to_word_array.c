/*
** EPITECH PROJECT, 2019
** Dante
** File description:
** str to tab
*/

#include <stdio.h>
#include <stdlib.h>

int count_words(char *str, char separator)
{
    int i = 0;
    int a = 0;
    int words = 0;

    while (str[i]) {
        if ((str[i] != separator && str[i] != '\t') && a == 0) {
            words += 1;
            a = 1;
        } else if (str[i] == separator || str[i] == '\t')
            a = 0;
        i++;
    }
    return (words);
}

char *count_letters(int *letters, char *str, char separator)
{
    int i = 0;
    int j = 0;
    char *word;
    *letters = 0;
    while (str[i] == separator || str[i] == '\t')
        i++;
    while ((str[i] != separator && str[i] != '\t') && str[i] != 0) {
        i += 1;
        *letters += 1;
    }
    *letters = i;
    word = malloc(sizeof(char) * (*letters + 1));
    if (word == NULL)
        return (NULL);
    for (j; str[j] == separator || str[j] == '\t'; j++);
    for (i = j; (str[i] != separator && str[i] != '\t' && str[i] != '\n')
    && str[i] != 0; i++)
        word[i - j] = str[i];
    word[i - j] = 0;
    return (word);
}

char **my_str_to_word_array(char *str, char separator)
{
    int words = 0;
    char *word = NULL;
    char **word_array = NULL;
    int letters = 0;
    int i = 0;

    if (!str || !str[0])
        return (NULL);
    words = count_words(str, separator);
    word_array = malloc(sizeof(char *) * (words + 1));
    for (i = 0; i < words; i++) {
        word = count_letters(&letters, str, separator);
        str += letters;
        word_array[i] = word;
    }
    if (word_array[i - 1][0] == '\0') {
        word_array[i - 1] = NULL;
    } else
        word_array[i] = NULL;
    return (word_array);
}