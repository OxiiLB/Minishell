/*
** EPITECH PROJECT, 2023
** cd_redirecting
** File description:
** all the function that redirect somewhere when cd is launched
*/

#include "my_lib.h"
#include "header.h"
#include <stdlib.h>
#include <unistd.h>

char *transform_tilde_into_home(char *path, char *home)
{
    int len = my_strlen(path) - 1 + my_strlen(home);
    char *new_path = malloc(sizeof(char) * len + 1);
    if (new_path == NULL)
        return NULL;
    new_path[0] = '\0';
    my_strcat(new_path, home);
    my_strcat(new_path, &path[1]);
    return new_path;
}

int pwd_redirect(char **env)
{
    char *pwd = put_backslash();
    char *oldpwd = put_backslash();
    oldpwd = getcwd(oldpwd, 1023);
    if (pwd == NULL)
        return -1;
    if (go_to(get_path_in_env(env, "OLDPWD=")) == -1)
        return -1;
    pwd = getcwd(pwd, 1023);
    set_variable_in_env(env, "PWD", pwd);
    set_variable_in_env(env, "OLDPWD", oldpwd);
    free(pwd);
    free(oldpwd);
    return 0;
}

int home_redirect(char **env, char *oldpwd, char *home)
{
    char *pwd = put_backslash();
    if (pwd == NULL)
        return -1;
    if (go_to(home) == -1)
        return -1;
    pwd = getcwd(pwd, 1023);
    set_variable_in_env(env, "PWD", pwd);
    set_variable_in_env(env, "OLDPWD", oldpwd);
    free(pwd);
    return 0;
}

int path_redirect(char *path, char **env, char *oldpwd, char *home)
{
    char *pwd = put_backslash();
    if (pwd == NULL)
        return -1;
    if (path[0] == '~') {
        if ((path = transform_tilde_into_home(path, home)) == NULL)
            return -1;
    }
    if (go_to(path) == -1)
        return -1;
    pwd = getcwd(pwd, 1023);
    set_variable_in_env(env, "PWD", pwd);
    set_variable_in_env(env, "OLDPWD", oldpwd);
    free(pwd);
    return 0;
}
