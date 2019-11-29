##
## EPITECH PROJECT, 2019
## 102architect_2019
## File description:
## Project makefile
##

SRC	=	main.c			\
		extract_arguments.c	\
		extract_arguments_ext.c	\
		make_matrix.c		\
		my_get_double.c		\
		display_result.c	\
		compute_matrix.c	\
		lib/my/my_put_double.c	\
		framebuffer.c			\
		framebuffer_ext.c			\
		framebuffer_shapes01.c	\
		framebuffer_shapes02.c	\
		run.c	\
		create_window.c

OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

CFLAGS	+= -Wall -Wextra -I./include -g

all:	$(NAME)

$(NAME):	$(OBJ) LIB
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy -lm -l csfml-graphics $(CFLAGS)

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:

.PHONY :        clean fclean re
