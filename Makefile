.PHONY: all, clean, fclean, re
	
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = fractol
LDFLAGS = -Llibft
LDLIBS = -lft
LIB_DIR = libft 
MINILIBX = minilibx
SRC = ./src/
INCLUDE = ./include/fractol.h

SRC_NAME = $(SRC)main.c \
			$(SRC)initialise.c\

OBJ = $(SRC_NAME:.c=.o)

$(NAME): $(OBJ)
		cd $(LIB_DIR) && make
		cd $(MINILIBX) && make
		$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -I $(INCLUDE) -o $@ minilibx/libmlx.a -lmlx -lm -framework OpenGL -framework AppKit
	
all : $(NAME)

clean :
	/bin/rm -f $(OBJ)
	cd $(LIB_DIR) && make $@
	cd $(MINILIBX) && make $@

fclean : clean
		/bin/rm -f $(NAME)
		/bin/rm -f libt/libft.a
		/bin/rm -f minilibx/libmlx.a

re : fclean all
		cd $(LIB_DIR)&& make
		cd $(MINILIBX) && make