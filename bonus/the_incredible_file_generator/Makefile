##
## EPITECH PROJECT, 2022
## B_MUL
## File description:
## my.h
##

CC = gcc
CFLAGS = -W -Wall -Wextra -g3

SRC = file_generator.c \
	error_gest.c \
	my_get_nbr.c
OBJ = $(SRC:.c=.o)

TARGET_RUN = file_generator

$(TARGET_RUN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)

all : $(TARGET_RUN) clean

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET_RUN)

re : fclean all
	rm -rf $(OBJ)
