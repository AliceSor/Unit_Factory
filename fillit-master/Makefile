# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makafile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asvirido <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 14:27:54 by asvirido          #+#    #+#              #
#    Updated: 2017/01/01 15:05:10 by asvirido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -c -Wall -Wextra -Werror

HEADER = head.h

SRC = ./functions/main.c\
	  ./functions/valid.c\
	  ./functions/ft_nlstadd.c\
	  ./functions/ft_nlstnew.c\
	  ./functions/open_read_close_file.c\
	  ./functions/ft_strlen.c\
	  ./functions/ft_strncpy.c\
	  ./functions/ft_strsplit.c\
	  ./functions/ft_bzero.c\
	  ./functions/ft_memset.c\
	  ./functions/ft_putstr.c\
	  ./functions/error.c\
	  ./functions/ft_print.c\
	  ./functions/algoritm.c\
	  ./functions/map_size.c\
	  ./functions/create_map.c\
	  ./functions/backtracking.c\
	  ./functions/is_place.c\
	  ./functions/place.c\
	  ./functions/fill.c\
	  ./functions/deleted.c\

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	gcc -o $(NAME) $(BINS)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o $@ $<

clean:
	 /bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norm:
	norminette *.c *.h
