##
## EPITECH PROJECT, 2019
## 102architect_2019
## File description:
## Project makefile
##

SRC	=	main.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

CFLAGS	+= -Wall -Wextra -I./include

all:	$(NAME)

$(NAME):	$(OBJ) LIB
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:

.PHONY :        clean fclean re
