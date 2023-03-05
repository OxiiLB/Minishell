/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** split an array in word array
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int my_strlen(char const *str);
bool my_isalnum(char c);
char *my_strncpy(char *dest, char const *src, int n);

char **malloc_words(char const *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;

    for (i = 0; str[i] != '\0'; i += 1) {
        if (my_isalnum(str[i]) == false)
            continue;
        count += 1;
        for (j = i + 1; str[i] != '\0' && my_isalnum(str[j]) == true; j += 1);
        i = j - 1;
    }
    char **res = malloc(sizeof(char *) * (count + 1));
    if (res == NULL)
        return NULL;
    return res;
}

char **my_str_to_word_array(char const *str)
{
    int j = 0;
    int k = 0;
    char **res = malloc_words(str);

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (my_isalnum(str[i]) == false)
            continue;
        for (j = i + 1; str[j] != '\0' && my_isalnum(str[j]) == true; j += 1);
        res[k] = malloc(sizeof(char) * (j - i + 1));
        if (res[k] == NULL)
            return NULL;
        my_strncpy(res[k], str + i, j - i);
        res[k][j - i] = '\0';
        k += 1;
        i = j - 1;
    }
    res[k] = NULL;

    return res;
}
