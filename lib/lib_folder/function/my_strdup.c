/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** dupplicates an str
*/

#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *str)
{
    int len = strlen(str) + 1;
    char *new_str = malloc(len);
    if (new_str == NULL) {
        return NULL;
    }
    memcpy(new_str, str, len);
    return new_str;
}
