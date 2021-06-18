##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile <alizee.soussan@epitech.eu>
##


SRC		=	src/main.c			\
			src/checker.c			\
			src/read.c

NAME	=	tail

COMPIL	=	-Llib/my -lmy

TFLAG	=	./tests/test_my_tail.c -lcriterion --coverage -fprofile-arcs

CFLAGS	=	-I include/

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		make clean -C lib/my
		gcc -o $(NAME) $(SRC) $(COMPIL) $(CFLAGS) -Wall -Wextra

clean:
		rm -f $(OBJ)
		rm -f *.o

fclean: clean
		rm -f $(NAME)
		make fclean -C lib/my

re:		fclean all

tests_run:
		make -C ./lib/my re
		gcc -o $(NAME) $(SRC) $(TFLAG) $(COMPIL) $(CFLAGS)
		-./$(NAME)
		gcovr --exclude tests/
		rm -f *.gcno
		rm -f *.gcda

debug:	$(OBJ)
		make -C lib/my
		make clean -C lib/my
		gcc -o $(NAME) $(SRC) $(COMPIL) -g $(CFLAGS)
