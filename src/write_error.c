/*
** EPITECH PROJECT, 2023
** write_error
** File description:
** write all the errors messages
*/

#include "my_lib.h"
#include <unistd.h>
#include <sys/wait.h>

int write_error_command(char **input_array)
{
    if (my_strcmp(input_array[0], "exit") != 0) {
        if (write(1, input_array[0], my_strlen(input_array[0])) == -1)
            return -1;
        if (write(1, ": Command not found.\n", 22) == -1)
            return -1;
    }
    if (my_strcmp(input_array[0], "exit") == 0 && input_array[1] != NULL) {
        if (write(1, "exit: Expression Syntax.\n", 26) == -1)
            return -1;
    }
    if (my_strcmp(input_array[0], "exit") == 0 && input_array[1] == NULL) {
        if (write(1, "exit\n", 5) == -1)
            return -1;
    }
    return 0;
}

int display_return_line_and_core_dumped(int return_value, int tmp_return_value
, int wstatus)
{
    tmp_return_value = WCOREDUMP(wstatus);
    if (tmp_return_value == 128) {
        if (write(2, " (core dumped)", 15) == -1)
            return -1;
        return_value += 128;
    }
    if (return_value > 8) {
        if (write(2, "\n", 1) == -1)
            return -1;
    }
    return WTERMSIG(wstatus) + WCOREDUMP(wstatus) + WEXITSTATUS(wstatus);
}

int write_error_binary(int wstatus)
{
    int return_value = 1;
    int tmp_return_value = 0;
    tmp_return_value = WTERMSIG(wstatus);
    if (tmp_return_value == 11) {
        if (write(2, "Segmentation fault", 19) == -1)
            return -1;
        return_value += 11;
    }
    if (tmp_return_value == 8) {
        if (write(2, "Floating exception", 19) == -1)
            return -1;
        return_value += 8;
    }
    return display_return_line_and_core_dumped
    (return_value, tmp_return_value, wstatus);
}
