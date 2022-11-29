/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:45:57 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/29 19:59:58 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_conversion(const char *format, va_list ap, int *len)
{
	char	c;

	if (*format == 'c')
	{
		c = (char)va_arg(ap, int);
		write(1, &c, 1);
		(*len) += 1;
	}
	else if (*format == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (*format == 'p')
		ft_memory(va_arg(ap, size_t), len);
	else if (*format == 'i' || *format == 'd')
		ft_num(va_arg(ap, int), len);
	else if (*format == 'u')
		ft_unsigned_int(va_arg(ap, unsigned int), len);
	else if (*format == 'x' || *format == 'X')
		ft_hexa(va_arg(ap, unsigned int), *format, len);
	else if (*format == '%')
	{
		write(1, "%", 1);
		(*len) += 1;
	}
	else
		write(1, format, 1);
}

void	check_format(const char *format, va_list ap, int *len)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_conversion(format, ap, len);
			format++;
		}
		else
		{
			write(1, format, 1);
			(*len) += 1;
			format++;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	check_format(format, ap, &len);
	va_end(ap);
	return (len);
}
