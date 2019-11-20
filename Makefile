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
		compute_matrix.c

OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ) LIB
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy -lm

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:

.PHONY :        clean fclean re
