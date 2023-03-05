/*
** EPITECH PROJECT, 2023
** display_env
** File description:
** dislpay the env
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_lib.h"

int display_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (write(1, array[i], my_strlen(array[i])) == -1)
            return -1;
        if (write(1, "\n", 1) == -1)
            return -1;
    }
    return 0;
}
