/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** my_strcat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int size_dest = my_strlen(dest);
    int i = 0;
    for (i = 0; src[i] != '\0' ; i++) {
        dest[size_dest + i] = src[i];
    }
    dest[size_dest + i] = '\0';
    return dest;
}
