NAME		=	philo

SRC			=	philo.c		\
				check_argv.c\
				error.c		\
				handler.c	\
				init.c		\
				get_time.c	\
				ft_usleep.c	\
				utils.c	\


OBJ			=	$(patsubst %.c,%.o,$(SRC))

CFLAGS		=	-Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				gcc $(OBJ) -o $@

%.o 		: %.c philo.h
				gcc -c $< -o $@

clean		:
				rm -f $(OBJ)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
