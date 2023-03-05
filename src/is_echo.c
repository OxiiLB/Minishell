/*
** EPITECH PROJECT, 2023
** is_echo
** File description:
** if mysh is launched with echo
*/

#include <sys/stat.h>
#include <unistd.h>

void is_echo_print_prompt(void)
{
    struct stat s;
    fstat(0, &s);
    if (S_ISFIFO(s.st_mode))
        return;
    write(1, "$> ", 4);
}

int is_echo(void)
{
    struct stat s;
    fstat(0, &s);
    if (S_ISFIFO(s.st_mode))
        return 1;
    return 0;
}
