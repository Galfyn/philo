NAME		=	philo

SRC			=	philo.c		\
				check_argv.c\
				error.c		\
				handler.c	\
				init.c		\
				get_time.c	\
				ft_usleep.c	\



OBJ			=	$(patsubst %.c,%.o,$(SRC))

CFLAGS		=	-Wall -Wextra -Werror

all			:	libft $(NAME)

$(NAME)		:	$(OBJ)
				gcc -Llibft -lft $(OBJ) -o $@

%.o 		: %.c philo.h
				gcc  -I./Libft -c $< -o $@

libft		:
				make -C Libft/

clean		:
				rm -f $(OBJ)
				make clean -C Libft/

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re libft
