##
## EPITECH PROJECT, 2022
## B_MUL
## File description:
## my.h
##

CC = gcc
CFLAGS = -W -Wall -Wextra -g3 -I. \
	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

SRC = main.c \
	square_collision.c \
	multi_type.c
OBJ = $(SRC:.c=.o)

TARGET_LIB = libcollision.a

all :
	$(CC) $(CFLAGS) $(SRC) -c
	ar rcs $(TARGET_LIB) $(OBJ)
	rm -rf $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET_LIB)

re : fclean all
