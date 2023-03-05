/*
** EPITECH PROJECT, 2023
** check_input
** File description:
** check if the input is empty
*/

int check_input(char *input)
{
    int nbr_char = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\t')
            input[i] = ' ';
        if (input[i] != ' ')
            nbr_char += 1;
    }
    if (nbr_char != 0)
        return 0;
    return 1;
}
