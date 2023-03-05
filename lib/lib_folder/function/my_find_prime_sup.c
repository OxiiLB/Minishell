/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** my_find_prime_sup
*/

int is_prime(int nb)
{
    int div = 2;
    int rest = 0;

    while (div < nb) {
        rest = nb % div;
        if (rest == 0) {
            return (0);
        }
        div = div + 1;
    }
    return (1);
}

int my_find_prime_sup (int nb)
{
    int i = nb;
    int result = 0;

    if (nb <= 2) {
        return (2);
    }
    while (i < 2147483646) {
        result = is_prime(i);
        if (result == 1) {
            return (i);
        }
        i = i + 1;
    }
    return (0);
}
