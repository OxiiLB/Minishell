/*
** EPITECH PROJECT, 2022
** my_str_islower
** File description:
** my_str_islower
*/

int my_str_islower(char const *str)
{
    int count = 0;

    if (str[0] == '\0') {
        return (1);
    }
    while (str[count] != '\0') {
        if ((str[count] < 'a' || str[count] > 'z') && (str[count] != ' ')) {
            return (0);
        }
        count = count + 1;
    }
    return (1);
}
