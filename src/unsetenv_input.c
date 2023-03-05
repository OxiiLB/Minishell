/*
** EPITECH PROJECT, 2023
** unsetenv_input
** File description:
** unset a varaible in the env
*/

#include "my_lib.h"
#include "header.h"
#include <stdlib.h>
#include <unistd.h>

char **delete_element(char ***array, int place)
{
    free((*array)[place]);
    for (; (*array)[place + 1] != NULL; place++) {
        (*array)[place] = (*array)[place + 1];
    }
    (*array)[place] = NULL;
    return *array;
}

char **unsetenv_input(char ***env, char **input_array)
{
    int size = 0;
    for (; input_array[size] != NULL; size++);
    if (size <= 1) {
        write(2, "unsetenv: Too few arguments.\n", 30);
        return 0;
    }
    for (int i = 1; input_array[i] != NULL; i++) {
        int place = 0;
        input_array[i] = my_realloc(input_array[i], 1);
        input_array[i] = my_strcat(input_array[i], "=");
        if (get_path_in_env(*env, input_array[i]) == NULL)
            continue;
        for (; my_strncmp(input_array[i], (*env)[place],
        my_strlen(input_array[i])) != 0; place++);
        *env = delete_element(env, place);
    }
    free_array(input_array);
    return *env;
}
