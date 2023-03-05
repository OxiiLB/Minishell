/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** my_strstr
*/

#include <stdio.h>
int my_strlen(char const *str);

char *my_strstr(char *str, char const *to_find)
{
    int count = 0;
    int i = 0;
    char *result;

    while (str[count] != '\0') {
        if (str[count] == to_find[i]) {
            result[i] = to_find[i];
            i = i + 1;
            count = count + 1;
        }
        count = count + 1;
    }
    return (result);
}
