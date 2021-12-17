NAME		=	philo

SRC			=	philo.c			\
				init.c			\
				utils_lib.c		\
				utils_philo.c	\
				threade.c		\


OBJ			=	$(patsubst %.c,%.o,$(SRC))

CFLAGS		=	-Wall -Wextra -Werror

all			:	$(NAME) clean

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
