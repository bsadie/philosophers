CC = clang
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRCS = philo.c		\
		utils.c		\
		check.c		\
		init.c		\
		time.c		\
		threads.c	\
		actions.c	\
		free.c
NAME = philo
HEADER = philo.h
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(INCLUDES) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

