/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** copy a array into another one
*/

char *my_strcpy(char *dest, char const *src)
{
    int count = 0;

    while (src[count] != '\0') {
        dest[count] = src[count];
        count = count + 1;
    }
    while (dest[count] != '\0') {
        dest[count] = '\0';
        count = count + 1;
    }
    return (dest);
}
