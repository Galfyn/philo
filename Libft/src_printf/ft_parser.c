/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:00:28 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/17 21:01:43 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_struct_init(t_format *spec)
{
	spec->minus = 0;
	spec->zero = 0;
	spec->width = 0;
	spec->dot = 0;
	spec->precision = 0;
	spec->type = 0;
}

static void	ft_pars(char **format, t_format *spec, va_list ap)
{
	while (!ft_isalpha(**format))
	{
		if (**format == '-')
			spec->minus = 1;
		if (**format == '0' && (*(*format - 1) == '%' || *(*format - 1) == '-'))
			spec->zero = 1;
		if (ft_isdigit(**format) && spec->dot != 1)
			spec->width = (spec->width * 10) + (**format - '0');
		if (**format == '*' && spec->dot != 1)
			spec->width = va_arg(ap, int);
		if (**format == '.')
			spec->dot = 1;
		if (ft_isdigit(**format) && spec->dot == 1)
			spec->precision = (spec->precision * 10) + (**format - '0');
		if (**format == '*' && spec->dot == 1)
			spec->precision = va_arg(ap, int);
		if (**format == '%')
			break ;
		(*format)++;
	}
}

int	ft_parser(char **format, va_list ap)
{
	t_format	spec;
	int			len;

	(*format)++;
	if (**format == '\0')
		return (0);
	ft_struct_init(&spec);
	len = 0;
	ft_pars(format, &spec, ap);
	len += ft_type(format, ap, &spec);
	return (len);
}
