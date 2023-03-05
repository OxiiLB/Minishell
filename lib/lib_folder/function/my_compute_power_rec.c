/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** recursive version of my_compute_power_it
*/

#include <stdio.h>

int my_compute_power_rec(int nb, int p)
{
    long int number = 0;
    int result = 0;

    if (p == 0) {
        return (1);
    }

    number = nb * my_compute_power_rec(nb, p - 1);

    if (number > 2147483647 || number < 2147483648) {
        return (0);
    } else {
        number = (int)result;
    }

    return (result);
}

int main(int argc, char)
{
    int nb = my_compute_power_rec(5, 4);
    return (0);
}
