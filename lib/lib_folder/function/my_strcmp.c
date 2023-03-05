/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** compare two str chars
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return 1;
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i += 1) {
        if (s1[i] - s2[i] != 0) {
            return (s1[i] - s2[i]);
        }
    }
    return 0;
}
