/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:27:20 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/27 20:46:40 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_memory(size_t address, int *len)
{
	char	str[32];
	int		i;

	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (address == 0)
	{
		write(1, "0", 1);
		(*len) += 1;
		return ;
	}
	while (address != 0)
	{
		str[i] = "0123456789abcdef"[address % 16];
		address = address / 16;
		i++;
	}
	while (i--)
	{
		write(1, &str[i], 1);
		(*len) += 1;
	}
}

void	ft_hexa(unsigned int x, char xx, int *len)
{
	char	str[32];
	int		i;

	i = 0;
	if (x == 0)
	{
		write(1, "0", 1);
		(*len) += 1;
		return ;
	}
	while (x != 0)
	{
		if (xx == 'X')
			str[i] = "0123456789ABCDEF"[x % 16];
		else
			str[i] = "0123456789abcdef"[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
	{
		write(1, &str[i], 1);
		(*len) += 1;
	}
}

void	ft_unsigned_int(unsigned int u, int *len)
{
	char	c;

	if (u >= 10)
		ft_unsigned_int(u / 10, len);
	c = u % 10 + '0';
	write(1, &c, 1);
	(*len) += 1;
}

void	ft_num(int number, int *len)
{
	char	c;

	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		(*len) += 1;
		ft_num(number * -1, len);
	}
	else
	{
		if (number > 9)
			ft_num(number / 10, len);
		c = number % 10 + '0';
		write(1, &c, 1);
		(*len) += 1;
	}
}
