/*
** EPITECH PROJECT, 2023
** waiting_exit
** File description:
** main loop of the program, exit if the function end
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_lib.h"
#include "header.h"

int recognize_input_2(char **input_array, char ***env, char *input)
{
    if (my_strcmp("cd", input_array[0]) == 0) {
        if (cd_input(*env, input_array) == -1)
            return -1;
        return 0;
    }
    if (my_strcmp("env", input_array[0]) == 0) {
        if (display_array(*env) == -1)
            return -1;
        return 0;
    }
    free_array(input_array);
    return exec_path_functions(*env, input);
}

int recognize_input(char *input, char ***env)
{
    char **input_array = my_spliter(input, ' ');
    if (input_array == NULL)
        return -1;
    if (my_strcmp("setenv", input_array[0]) == 0) {
        if ((*env = setenv_input(env, input_array)) == NULL)
            return -1;
        return 0;
    }
    if (my_strcmp("unsetenv", input_array[0]) == 0) {
        if ((*env = unsetenv_input(env, input_array)) == NULL)
            return -1;
        return 0;
    }
    return recognize_input_2(input_array, env, input);
}

char *print_prompt_and_get_path(char *input)
{
    is_echo_print_prompt();
    if ((input = put_teminal_in_str()) == NULL)
        return NULL;
    return input;
}

bool print_exit(char *input)
{
    char **input_array = my_spliter(input, ' ');
    if (my_strcmp("exit", input_array[0]) == 0 && input_array[1] == NULL) {
        write_error_command(input_array);
        free_array(input_array);
        return true;
    }
    free_array(input_array);
    return false;
}

int waiting_exit(char ***env)
{
    char *input = NULL;
    int return_value = 0;
    while (return_value != -2) {
        if ((input = print_prompt_and_get_path(input)) == NULL)
            return 0;
        if (check_input(input) == 1)
            continue;
        if (print_exit(input) == true) {
            free(input);
            free_array(*env);
            return return_value;
        }
        return_value = recognize_input(input, env);
        if (return_value == -1)
            return 84;
        if (is_echo() == 1)
            return return_value;
    }
    return 0;
}
