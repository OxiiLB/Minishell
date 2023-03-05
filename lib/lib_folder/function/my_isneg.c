/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** return if it's negative or not
*/

int my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
