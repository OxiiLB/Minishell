/*
** EPITECH PROJECT, 2023
** add_element
** File description:
** add an element in a char **
*/

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "my_lib.h"

char **add_element(char ***array, char *input)
{
    int len = 0;
    int i = 0;
    for (; (*array)[len] != NULL; len++);
    char **new_array = malloc(sizeof(char *) * (len + 2));
    if (new_array == NULL)
        return NULL;
    for (; i < len; i++)
        new_array[i] = (*array)[i];
    new_array[len] = input;
    new_array[len + 1] = NULL;
    *array = new_array;
    return new_array;
}
