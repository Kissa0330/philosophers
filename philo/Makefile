# CFLAGS = -Wall -Wextra -Werror 
NAME = philo
SRCS = srcs/main.c srcs/utils.c
OBJ = $(SRCS:%.c=%.o)

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