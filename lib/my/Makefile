##
## EPITECH PROJECT, 2020
## dante
## File description:
## Makefile lib
##

SRC	=	my_strlen.c					\
		my_putstr.c					\
		my_putchar.c				\
		my_putnbr.c					\
		my_puterr.c					\
		my_getnbr.c					\
		my_strcat.c					\
		fs_cat_x_bytes.c			\
		my_str_to_word_array.c		\
		input.c						\
		my_strcmp.c					\
		error_handling_caracters.c	\
		error_handling_boats.c		\
		add_boats.c					\
		create_maps.c				\
		print_maps.c				\
		send_attacks.c				\
		connexion.c					\
		receive_attack_coord.c		\
		receive_hit_miss.c			\
		send_hit_miss.c				\
		player_one.c				\
		player_two.c				\
		description.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/
	cp struct.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm ../$(NAME)

re:	fclean	all
