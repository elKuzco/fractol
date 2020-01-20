.PHONY: all, clean, fclean, re
	
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = fractol
LDFLAGS = -Llibft
LDLIBS = -lft
LIB_DIR = libft 
MINILIBX = minilibx
SRC = ./src/
INCLUDE = ./include/fractol.h \
			./include/colors.h \

SRC_NAME = $(SRC)main.c \
			$(SRC)initialise.c\
			$(SRC)display.c\
			$(SRC)mandelbrot.c\
			$(SRC)inputs.c\
			$(SRC)color.c\
			$(SRC)threads.c\
			$(SRC)julia.c\
			$(SRC)hazard.c\
			$(SRC)tricorn.c\
			$(SRC)burningship.c\
			$(SRC)mandelbrot3.c\
			$(SRC)julia3.c\
			$(SRC)ui.c\
			$(SRC)phoenix.c\
			$(SRC)feigenbaum.c\
			$(SRC)heart.c\
			$(SRC)pines.c\
			$(SRC)menu.c\

OBJ = $(SRC_NAME:.c=.o)

$(NAME): $(OBJ) Makefile $(INCLUDE)
		cd $(LIB_DIR) && make
		cd $(MINILIBX) && make
		$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@ -lmlx -lm -framework OpenGL -framework AppKit
	
all : $(NAME)

clean :
	/bin/rm -f $(OBJ)
	cd $(LIB_DIR) && make $@
	cd $(MINILIBX) && make $@

fclean : clean
		/bin/rm -f $(NAME)
		/bin/rm -f libft/libft.a
		/bin/rm -f minilibx/libmlx.dylib

re : fclean all
		cd $(LIB_DIR)&& make
		cd $(MINILIBX) && make