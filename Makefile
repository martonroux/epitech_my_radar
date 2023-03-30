##
## EPITECH PROJECT, 2022
## Project
## File description:
## makefile.c
##

CFLAGS = -W -Wall -Wextra -g3 \
	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

SRC = main.c \
	lib/init_data.c \
	lib/init_data_bis.c \
	lib/init_data_tris.c \
	lib/init_data_quad.c \
	lib/my_functions.c \
	lib/linked_list.c \
	lib/render.c \
	lib/my_sfintrect_col.c \
	lib/check_area.c \
	lib/check_collision.c \
	lib/actions_main.c \
	lib/complements.c \
	lib/error_gest.c \
	lib/complements_bis.c
OBJ = $(SRC:.c=.o)

LIB = lib/collision/libcollision.a

TARGET_RUN = my_radar

$(TARGET_RUN) : $(OBJ)
	make all -C ./lib/collision
	gcc -o $@ $(OBJ) $(CFLAGS) -Llib/collision -lcollision

all : $(TARGET_RUN) clean

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET_RUN)

re : fclean all
	rm -rf $(OBJ)
