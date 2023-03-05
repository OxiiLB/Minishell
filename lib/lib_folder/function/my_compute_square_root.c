/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int count = 0;
    int result = 0;

    while (count < nb) {
        result = count * count;
        if (result == nb) {
            return (count);
        }
        count = count + 1;
    }
    if (result != nb) {
        return (0);
    }
    return (count);
}
