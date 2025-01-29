NAME = weapon

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME)
	@echo "Compilation complete !"

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all