/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** return the length of a string
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int count = 0;
    if (str == NULL)
        return -1;
    for (count = 0; str[count] != '\0'; count++);
    return count;
}
