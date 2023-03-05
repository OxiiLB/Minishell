/*
** EPITECH PROJECT, 2023
** tests
** File description:
** all the unit tests for the project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header.h"
#include "my_lib.h"

void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}
