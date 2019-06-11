# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoroka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/25 18:13:07 by asoroka           #+#    #+#              #
#    Updated: 2017/05/01 20:54:44 by asoroka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -c #-Wall -Wextra -Werror 

MLX = -lmlx -framework OpenGL -framework AppKit

HEADER = fractol.h

SRC = src/create_win.c		\
	  src/create_image.c 	\
	  src/mandelbrot.c		\
	  src/scale_re.c		\
	  src/put_pixel.c		\
	  src/main.c			\
	  src/buttons.c			\
	  src/set_limits.c		\
	  src/algoritm.c		\
	  src/zoom.c			\
	  src/set_new_limits.c	\
	  src/create_fractol.c	\
	  src/julia.c			\
	  src/mouse_julia.c		\

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
		gcc -o $(NAME) $(BINS) $(MLX)
		make clean
%.o: %.c $(HEADER)
		gcc $(FLAGS) -o $@ $<

clean:
	 /bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
