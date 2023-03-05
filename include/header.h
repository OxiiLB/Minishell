/*
** EPITECH PROJECT, 2023
** header
** File description:
** header of the project
*/

#ifndef HEADER_S
    #define HEADER_S

    char *put_teminal_in_str(void);
    int waiting_exit(char ***env);
    int recognize_input(char *input, char ***env);
    int exec_path_functions(char **env, char *input);
    char *my_realloc(char *str, int size);
    char **get_path(char **input_array, char *path);
    int child_process(char **env, char **input_array, char **path_array);
    int cd_input(char **env, char **input_array);
    char *get_path_in_env(char **env, char *path_name);
    void free_all(char **input_array, char **path_array);
    void free_array(char **env);
    char **setenv_input(char ***env, char **input_array);
    char **add_element(char ***array, char *input);
    int display_array(char **array);
    char **unsetenv_input(char ***env, char **input_array);
    int write_error_command(char **input_array);
    int write_error_binary(int return_value);
    int check_input(char *input);
    int set_variable_in_env(char **env, char *variable, char *value);
    int go_to(char *path);
    int pwd_redirect(char **env);
    int home_redirect(char **env, char *oldpwd, char *home);
    int path_redirect(char *path, char **env, char *oldpwd, char *home);
    char *put_backslash(void);
    void is_echo_print_prompt(void);
    int is_echo(void);
    char **copy_env(char **env);

#endif /* !HEADER_S */
