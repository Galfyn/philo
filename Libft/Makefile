# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galfyn <galfyn@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/18 22:14:35 by galfyn            #+#    #+#              #
#    Updated: 2021/11/04 14:22:40 by galfyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_memset.c		ft_bzero.c		ft_memcpy.c		\
		ft_memccpy.c	ft_memmove.c	ft_memchr.c		\
		ft_memcmp.c		ft_strlen.c		ft_isalpha.c	\
		ft_isdigit.c	ft_isalnum.c	ft_islower.c	\
		ft_isupper.c	ft_isprint.c	ft_isnotprint.c	\
		ft_isascii.c	ft_toupper.c	ft_tolower.c	\
		ft_strchr.c		ft_memrchr.c	ft_strrchr.c	\
		ft_strncmp.c	ft_strlcpy.c	ft_strlcat.c	\
		ft_split.c		ft_atoi.c		ft_putnbr_fd.c	\
		ft_isspace.c	ft_calloc.c		ft_strnstr.c	\
		ft_calloc.c		ft_strdup.c		ft_substr.c		\
		ft_strjoin.c	ft_strmapi.c	ft_itoa.c		\
		ft_strtrim.c	ft_putchar_fd.c	ft_putstr_fd.c	\
		ft_putendl_fd.c	get_next_line.c	ft_printf.c		\
		ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	\
		ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	\
		ft_lstclear.c	ft_lstiter.c		ft_lstmap.c		\
		src_printf/ft_count_int.c		\
		src_printf/ft_parser.c			\
		src_printf/ft_print_int.c		\
		src_printf/ft_type.c			\
		src_printf/ft_print_pointer.c	\
		src_printf/ft_count_hex.c		\
		src_printf/ft_print_hex.c		\
		src_printf/ft_putnbr_hex.c		\
		src_printf/ft_print_char.c		\
		src_printf/ft_print_string.c	\

OBJ = $(patsubst %.c,%.o,$(SRC))


FLAGS = -Wall -Wextra -Werror -I.

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c libft.h
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(OBJ_B)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY : clean fclean re all bonus
