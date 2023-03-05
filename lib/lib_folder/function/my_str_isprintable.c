/*
** EPITECH PROJECT, 2022
** my_str_isprintable
** File description:
** my_str_isprintable
*/

int my_str_isprintable(char const *str)
{
    int count = 0;

    if (str[0] == '\0') {
        return (1);
    }
    while (str[count] != '\0') {
        if ((str[count] < ' ' || str[count] > '~') && (str[count] != ' ')) {
            return (0);
        }
        count = count + 1;
    }
    return (1);
}
