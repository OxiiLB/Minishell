/*
** EPITECH PROJECT, 2023
** set_variable_in_env
** File description:
** set a variable with the value given
*/

#include <stdlib.h>
#include "my_lib.h"
#include "header.h"

int set_variable_in_env(char **env, char *variable, char *value)
{
    int place = 0;
    variable = my_realloc(variable, 1);
    if (variable == NULL)
        return -1;
    variable = my_strcat(variable, "=");
    if (get_path_in_env(env, variable) == NULL)
        return 0;
    for (; my_strncmp(env[place], variable, my_strlen(variable)) != 0;
    place++);
    free(env[place]);
    env[place] = malloc(sizeof(char) * (my_strlen(variable) +
    my_strlen(value) + 1));
    if (env[place] == NULL)
        return -1;
    env[place][0] = '\0';
    my_strcat(env[place], variable);
    my_strcat(env[place], value);
    return 0;
}
