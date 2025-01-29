NAME = animal

SRC = WrongAnimal.cpp WrongCat.cpp Animal.cpp Cat.cpp Dog.cpp main.cpp

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)
	@echo "Compilation complete !"

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all