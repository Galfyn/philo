NAME		=	philo
NAME_B		=	philo_bonus

SRC			=	philo.c				\
				init.c				\
				utils_lib.c			\
				utils_philo.c		\
				thread.c			\

SRC_B		=	bonus/philo_bonus.c \
				bonus/utils_bonus.c	\
				bonus/utils_lib.c	\

GREEN		=	\033[32m\033[1m


OBJ			=	$(patsubst %.c,%.o,$(SRC))
OBJ_B		=	$(patsubst %.c,%.o,$(SRC_B))

CFLAGS		=	-Wall -Wextra -Werror

all			:	$(NAME)

bonus		:	$(NAME_B)

$(NAME)		:	$(OBJ)
				@gcc $(CFLAGS) $(OBJ) -o $@
				@echo "$(GREEN) Completed"

%.o 		:	%.c philo.h
				@gcc  -c $< -o $@

$(NAME_B)	:	$(OBJ_B)
				@gcc $(CFLAGS) $(OBJ_B) -o $@
				@echo "$(GREEN) Completed bonus"

clean		:
				@rm -f $(OBJ)
				@rm -f $(OBJ_B)
				@echo "$(GREEN) clean completed"


fclean		:	clean
				@rm -f $(NAME)
				@rm -f $(NAME_B)


re			:	fclean all

.PHONY		:	all clean fclean re bonus
