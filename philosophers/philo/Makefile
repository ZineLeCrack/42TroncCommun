NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c srcs/utils.c srcs/create_philosophers.c srcs/eat_sleep.c srcs/destroy.c srcs/check_error.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all