/*
** EPITECH PROJECT, 2023
** my_isalphanum
** File description:
** check if the char is alphanum or not
*/

#include <stdbool.h>

bool my_isalnum(char c)
{
    if ((c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z') ||
    (c >= '0' && c <= '9')) {
        return true;
    }
    return false;
}
