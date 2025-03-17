NAME = bureaucrat

SRCS = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
	   PresidentialPardonForm.cpp Intern.cpp main.cpp

CC = c++ -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "Compilation complete !"

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf home_shrubbery

re: fclean all

.PHONY: all clean fclean re