/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main of the program
*/

#include "my_lib.h"
#include "header.h"
#include <unistd.h>
#include <stdlib.h>

char **copy_env(char **env)
{
    char **env_copy = NULL;
    int nbr_line = 0;
    int len_line = 0;
    for (nbr_line = 0; env[nbr_line] != NULL; nbr_line++);
    env_copy = malloc(sizeof(char *) * (nbr_line + 1));
    if (env_copy == NULL)
        return NULL;
    env_copy[nbr_line] = NULL;
    for (int i = 0; env[i] != NULL; i++) {
        len_line = my_strlen(env[i]);
        env_copy[i] = malloc(sizeof(char) * (len_line + 1));
        if (env_copy[i] == NULL)
            return NULL;
        env_copy[i][len_line] = '\0';
        for (int j = 0; env[i][j] != '\0'; j++)
            env_copy[i][j] = env[i][j];
    }
    return env_copy;
}

int main(int const argc, char const * const * const argv, char **env)
{
    if (env == NULL)
        return 84;
    char **env_copy = copy_env(env);
    if (env_copy == NULL)
        return 84;
    if (argc == 2 || argv[1] != NULL)
        return 84;
    return waiting_exit(&env_copy);
}
