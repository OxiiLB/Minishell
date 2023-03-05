/*
** EPITECH PROJECT, 2023
** input ls
** File description:
** function that launch ls function in C lib
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include "my_lib.h"
#include "header.h"

char **get_path(char **input_array, char *path)
{
    char **path_array = my_spliter(path, ':');
    for (int j = 0; path_array[j] != NULL; j++) {
        path_array[j] = my_realloc(path_array[j],
        my_strlen(input_array[0]) + 1);
        if (path_array[j] == NULL)
            return NULL;
        path_array[j] = my_strcat(path_array[j], "/");
        path_array[j] = my_strcat(path_array[j], input_array[0]);
    }
    return path_array;
}

int child_process(char **env, char **input_array, char **path_array)
{
    execve(input_array[0], input_array, env);
    for (int i = 0; path_array[i] != NULL; i++)
        execve(path_array[i], input_array, env);
    if (write_error_command(input_array) == -1)
        return -1;
    free_all(input_array, path_array);
    free_array(env);
    exit(1);
}

int fork_process(char **env, char **input_array,
char **path_array)
{
    __pid_t pid = fork();
    if (pid == -1)
        return -1;
    int wstatus = 0;
    if (pid == 0)
        return child_process(env, input_array, path_array);
    else {
        waitpid(pid, &wstatus, 0);
        free_all(input_array, path_array);
        int return_value = write_error_binary(wstatus);
        return return_value;
    }
    return -1;
}

int exec_path_functions(char **env, char *input)
{
    if (my_strlen(input) < 1)
        return 0;
    char *path = get_path_in_env(env, "PATH=");
    if (path == NULL)
        return 0;
    char **input_array = my_spliter(input, ' ');
    char **path_array = get_path(input_array, path);
    if (path_array == NULL || input_array == NULL)
        return -1;
    return fork_process(env, input_array, path_array);
}
