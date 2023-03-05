/*
** EPITECH PROJECT, 2023
** get_path_in_env
** File description:
** get the path given in the env
*/

#include "my_lib.h"
#include "header.h"
#include <unistd.h>

char *get_path_in_env(char **env, char *path_name)
{
    int i = 0;
    for (; env[i] != NULL; i++) {
        if (my_strncmp(env[i], path_name, my_strlen(path_name)) == 0)
            return &(env[i][my_strlen(path_name)]);
    }
    return NULL;
}
