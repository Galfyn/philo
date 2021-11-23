NAME		=	philo

SRCS		=	srcs/philo.c	\
				srcs/check_argv	\


OBJ			=	$(patsubst %.c,%.o,$(SRCS))

CFLAGS		=	-Wall -Wextra -Werror -lpthreade

NAME		:	$(OBJ)
				gcc $(OBJ) -o $(NAME)

all			:	$(NAME)

clean		:
				rm -f $(OBJ)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
