/*
** EPITECH PROJECT, 2023
** setenv_input
** File description:
** when the input is setenv
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_lib.h"
#include "header.h"

int set_exist_variable_with_value(char ***env, char **input_array,
char *tmp_input)
{
    if (input_array[2] == NULL) {
        if (set_variable_in_env(*env, tmp_input, "") == -1)
            return -1;
        return 0;
    }
    if (set_variable_in_env(*env, tmp_input, input_array[2]) == -1)
        return -1;
    return 0;
}

int set_exist_variable_without_value(char ***env, char **input_array)
{
    char *tmp_input = malloc(sizeof(char) * my_strlen(input_array[1]) + 1);
    tmp_input[my_strlen(input_array[1])] = '\0';
    tmp_input = my_strcpy(tmp_input, input_array[1]);
    input_array[1] = my_realloc(input_array[1], 1);
    if (input_array[1] == NULL)
        return -1;
    input_array[1] = my_strcat(input_array[1], "=");
    if (get_path_in_env(*env, input_array[1]) != NULL) {
        if (set_exist_variable_with_value(env, input_array, tmp_input) == -1)
            return -1;
    }
    free(tmp_input);
    return 0;
}

char **set_none_exist_variable(char ***env, char **input_array)
{
    if (input_array[2] != NULL) {
        input_array[1] = my_realloc(input_array[1],
        my_strlen(input_array[2]));
        my_strcat(input_array[1], input_array[2]);
    }
    if (get_path_in_env(*env, input_array[1]) == NULL) {
        if ((*env = add_element(env, input_array[1])) == NULL)
            return NULL;
    }
    return *env;
}

char **setenv_input(char ***env, char **input_array)
{
    if (input_array == NULL)
        return NULL;
    int nbr_words = 0;
    for (; input_array[nbr_words] != NULL; nbr_words++);
    if (nbr_words == 1)
        display_array(*env);
    if (nbr_words == 2 || nbr_words == 3) {
        if (set_exist_variable_without_value(env, input_array) == -1)
            return NULL;
        if ((*env = set_none_exist_variable(env, input_array)) == NULL)
            return NULL;
    }
    if (nbr_words > 3) {
        if (write(2, "setenv: Too many arguments.\n", 29) == -1)
            return NULL;
    }
    return *env;
}
