/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** display a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        my_putchar(str[count]);
        count = count + 1;
    }
    return (0);
}
