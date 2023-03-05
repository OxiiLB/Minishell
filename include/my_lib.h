/*
** EPITECH PROJECT, 2022
** my
** File description:
** prototypes of all functions in libmy.a
*/
#ifndef TEST

    #define TEST

    #include <stdarg.h>
    #include <stdbool.h>

    void my_putchar(char c);
    int my_isneg(int nb);
    int my_put_nbr(int n);
    void my_swap(int *a, int *b);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_getnbr(char const *str);
    void my_sort_int_array(int *tab, int size);
    int my_compute_power_rec(int nb, int power);
    int my_compute_square_root(int nb);
    int my_is_prime(int nb);
    int my_find_prime_sup(int nb);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_revstr(char *str);
    char *my_strstr(char *str, char const *to_find);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    char *my_strcapitalize(char *str);
    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    int my_str_islower(char const *str);
    int my_str_isupper(char const *str);
    int my_str_isprintable(char const *str);
    int my_showstr(char const *str);
    int my_showmem(char const *str, int size);
    char *my_strcat(char *dest, char const *src);
    char *my_strncat(char *dest, char const *src, int nb);
    char **my_str_to_word_array(char const *str);
    char **my_spliter(char const *str, char separator);
    char *my_strdup(const char *str);
    int my_printf(const char *format, ...);
    int function_c(const char *format, int count, va_list list, int precision);
    int function_i(char const *format, int count, va_list list, int precision);
    int function_s(const char *format, int count, va_list list, int precision);
    int function_o(char const *format, int count, va_list list, int precision);
    int function_e(char const *format, int count, va_list list, int precision);
    int function_f(const char *format, int count, va_list list, int precision);
    int function_u(char const *format, int count, va_list list, int precision);
    int function_d(const char *format, int count, va_list list, int precision);
    int function_n(char const *format, int count, va_list list, int precision);
    int function_x(char const *format, int count, va_list list, int precision);
    int function_percentage(char const *format, int count, va_list list,
    int precision);
    int function_e_maj(const char *format, int count, va_list list,
    int precision);
    int function_f_maj(const char *format, int count, va_list list,
    int precision);
    int function_x_maj(char const *format, int count, va_list list,
    int precision);
    int find_flag(char my_flag, int count, char const *format, va_list list);
    void my_putchar(char c);
    int my_put_nbr(int nb);
    int my_strlen(char const *str);
    int count_digit(unsigned int nbr_tpm);

#endif /*TEST*/
