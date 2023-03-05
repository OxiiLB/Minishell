/*
** EPITECH PROJECT, 2022
** my_str_isupper
** File description:
** my_str_isupper
*/

int my_str_isupper(char const *str)
{
    int count = 0;

    if (str[0] == '\0') {
        return (1);
    }
    while (str[count] != '\0') {
        if ((str[count] < 'A' || str[count] > 'Z') && (str[count] != ' ')) {
            return (0);
        }
        count = count + 1;
    }
    return (1);
}
