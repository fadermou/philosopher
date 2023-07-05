NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror #-pthread -g3 -fsanitize=thread
SRCS =  philosopher.c parsing.c ft_time.c ft_atoi.c\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all 