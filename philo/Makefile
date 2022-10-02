CFLAGS = -Wall -Wextra -Werror 
NAME = philo
SRCS = main.c utils.c philo.c init.c monitor.c
OBJ = $(SRCS:%.c=%.o)
VPATH = srcs

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all