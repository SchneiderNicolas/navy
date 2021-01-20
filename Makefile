##
## EPITECH PROJECT, 2020
## dante
## File description:
## Makefile
##

SRC	=	main.c		\

NAME	=	navy

OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) -L lib/my -lmy -g

all: $(NAME)

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean	all