/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reverse a string
*/

#include <stdio.h>

int len(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count = count + 1;
    }
    return (count);
}

char *my_revstr(char *str)
{
    int count = len(str);
    char tmp = '\0';
    int i = 0;

    count = count - 1;

    while (i < count) {
        tmp = str[i];
        str[i] = str[count];
        str[count] = tmp;
        i = i + 1;
        count = count - 1;
    }
    return (str);
}
