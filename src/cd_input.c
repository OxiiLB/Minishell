/*
** EPITECH PROJECT, 2023
** cd_input
** File description:
** program that can go in a path given
*/

#include "my_lib.h"
#include "header.h"
#include <unistd.h>
#include <stdlib.h>

char *put_backslash(void)
{
    char *pwd = malloc(sizeof(char) * 1024);
    if (pwd == NULL)
        return NULL;
    for (int i = 0; i != 1023; i++) {
        pwd[i] = '\0';
    }
    return pwd;
}

int cd_input(char **env, char **input_array)
{
    char *pwd = put_backslash();
    pwd = getcwd(pwd, 1023);
    char *home = get_path_in_env(env, "HOME=");
    int len = 0;
    for (; input_array[len] != NULL; len++);
    if (len == 1 || my_strcmp(input_array[1], "~") == 0)
        home_redirect(env, pwd, home);
    if (len == 2 && my_strcmp(input_array[1], "-") != 0)
        path_redirect(input_array[1], env, pwd, home);
    if (len == 2 && my_strcmp(input_array[1], "-") == 0)
        pwd_redirect(env);
    if (len > 2)
        if (write(2, "cd: Too many arguments.\n", 25) == -1)
            return -1;
    free_array(input_array);
    free(pwd);
    return 0;
}
