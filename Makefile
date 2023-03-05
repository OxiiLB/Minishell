##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## compil project binary
##

SRC			=	src/main.c									\
				src/put_str_in_terminal.c					\
				src/waiting_exit.c							\
				src/exec_path_functions.c					\
				src/my_realloc.c							\
				src/cd_input.c								\
				src/get_path_in_env.c						\
				src/free_all.c								\
				src/setenv_input.c							\
				src/display_array.c							\
				src/add_element.c							\
				src/unsetenv_input.c						\
				src/write_error.c							\
				src/check_input.c							\
				src/set_variable_in_env.c					\
				src/cd_redirecting.c						\
				src/go_to.c									\
				src/is_echo.c

SRC_TEST	=	src/put_str_in_terminal.c					\
				src/waiting_exit.c							\
				src/exec_path_functions.c					\
				src/my_realloc.c							\
				src/cd_input.c								\
				src/get_path_in_env.c						\
				src/free_all.c								\
				src/setenv_input.c							\
				src/display_array.c							\
				src/add_element.c							\
				src/unsetenv_input.c						\
				src/write_error.c							\
				src/check_input.c							\
				src/set_variable_in_env.c					\
				src/cd_redirecting.c						\
				src/go_to.c									\
				src/is_echo.c

OBJ			=	$(SRC:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./include/

NAME		=	mysh

MY_LIB		=	-L lib/lib_folder -lmy_lib

all: 	make_lib $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(MY_LIB)

make_lib:
	make -C lib/lib_folder

clean:
	make -C lib/lib_folder clean
	rm -f $(OBJ) vgcore* *.gc*

fclean:	clean
	make -C lib/lib_folder fclean
	rm -f $(NAME)
	rm -f unit_tests*

re:	fclean all

build_test:	make_lib $(OBJ_TEST)
	gcc -o unit_tests $(OBJ_TEST) tests/tests.c --coverage -lcriterion \
	$(CPPFLAGS) $(MY_LIB)

tests_run: build_test
	./unit_tests

.PHONY: all clean fclean re make_lib tests_run build_test
