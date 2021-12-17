# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galfyn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 14:58:37 by galfyn            #+#    #+#              #
#    Updated: 2021/12/14 15:30:35 by galfyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_bonus

SRCS		=	check_argv.c	\
				error.c			\
				get_time.c		\
				init.c			\
				philo_bonus.c	\
				utils.c			\

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

CFLAGS		=	-Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				gcc $(OBJS) -o $@

%.o			:	%.c philo_bonus.h
				gcc -c $< -o $@

clean		:
				rm -f $(OBJS)

fclean		: 	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		: all clean fclean re
