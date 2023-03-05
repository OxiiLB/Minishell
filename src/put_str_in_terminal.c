/*
** EPITECH PROJECT, 2023
** put terminal in str
** File description:
** put_terminal_in_str
*/

#include <stdio.h>
#include <unistd.h>
#include "my_lib.h"

char *put_teminal_in_str(void)
{
    char *line = NULL;
    size_t len = 0;
    int getline_value = getline(&line, &len, stdin);
    line[my_strlen(line) - 1] = '\0';
    if (getline_value == -1)
        return NULL;
    return line;
}
