/*
** EPITECH PROJECT, 2023
** my_realloc
** File description:
** like realloc
*/

#include <stdlib.h>
#include "my_lib.h"

char *my_realloc(char *str, int size)
{
    int new_size = my_strlen(str) + size;
    int i = 0;
    char *output = malloc(sizeof(char) * (new_size + 1));
    if (output == NULL)
        return NULL;
    for (; str[i] != '\0'; i++) {
        output[i] = str[i];
    }
    output[i] = '\0';
    return output;
}
