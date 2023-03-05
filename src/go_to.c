/*
** EPITECH PROJECT, 2023
** go_to
** File description:
** go to the path given
*/

#include "my_lib.h"
#include <unistd.h>

int go_to(char *path)
{
    if (chdir(path) == -1) {
        if (write(2, "cd: no such file or directory: ", 32) == -1)
            return -1;
        if (write(2, path, my_strlen(path)) == -1)
            return -1;
        if (write(2, "\n", 1) == -1)
            return -1;
        return 0;
    }
    return 0;
}
