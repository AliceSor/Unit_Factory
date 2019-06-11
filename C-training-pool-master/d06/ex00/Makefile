NAME = convert
CPPFLAGS = -Wall -Wextra -Werror
CC = clang++
SRC = Converter.cpp main.cpp
OBJ=$(SRC:.cpp=.o)

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

.cpp.o:
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
