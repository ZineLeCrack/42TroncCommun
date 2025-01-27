SRC = megaphone.cpp

NAME = megaphone

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)
	@echo "Compilation complete !"

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all