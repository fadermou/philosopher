NAME = philo

# NAME_B = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread
# thread

SRCS =  philosopher.c parsing.c ft_time.c ft_atoi.c\
		# mutex_creation.c
		
		
		
		

# SRCS_B =  bonus/bonus.c bonus/check.c bonus/ft_atoi.c bonus/inst_push.c bonus/inst_rotate.c bonus/inst_swap.c bonus/lst_utils.c bonus/libft/ft_strdup.c\
# 		bonus/libft/ft_substr.c bonus/libft/ft_split.c bonus/utils.c bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c bonus/checker.c bonus/libft/ft_strcmp.c\
# 		bonus/inst_rotate2.c
		

OBJ = $(SRCS:.c=.o)

# OBJ_B = $(SRCS_B:.c=.o)


all : $(NAME)

# bonus : $(NAME_B)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

# $(NAME_B) : $(OBJ_B)
# 	$(CC) $(CFLAGS) $(OBJ_B)  -o $(NAME_B)

push :
	git add . && git commit -m "philosopher" && git push

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all 