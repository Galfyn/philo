/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:12:57 by galfyn            #+#    #+#             */
/*   Updated: 2021/12/10 19:07:53 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_format
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	precision;
	int	type;
}	t_format;

char	*ft_itoa(int n);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isspace(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isnotprint(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strrchr(const char *str, int ch);
void	*ft_memset(void *b, int c, size_t len);
void	ft_lstadd_front(t_list **lst, t_list *new);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
void	*ft_memchr(const void *arr, int c, size_t n);
void	*ft_memrchr(const void *arr, int c, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_memcmp(const void *arr1, const void *arr2, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	*ft_memcpy(void *destination, const void *source, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		get_next_line(int fd, char **line);

int		ft_printf(const char *format, ...);

int		ft_type(char **format, va_list ap, t_format *spec);
int		ft_parser(char **format, va_list ap);

int		ft_print_string(char *string, t_format *spec);
int		ft_print_pointer(unsigned long pointer, t_format *spec);
int		ft_print_char(int symbol, t_format *spec);
int		ft_print_int(long integer, t_format *spec);
int		ft_print_hex(unsigned int hex, t_format *spec);

int		ft_count_int(long integer);
int		ft_count_hex(unsigned long hex, t_format *spec);
int		ft_putnbr_hex(unsigned long pointer, t_format *spec);

#endif
