/*
** EPITECH PROJECT, 2023
** free_all
** File description:
** free all in the end of functions
*/

#include <unistd.h>
#include <stdlib.h>

void free_all(char **input_array, char **path_array)
{
    for (int i = 0; input_array[i] != NULL; i++)
        free(input_array[i]);
    free(input_array);
    for (int i = 0; path_array[i] != NULL; i++)
        free(path_array[i]);
    free(path_array);
}

void free_array(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        free(env[i]);
    free(env);
}
