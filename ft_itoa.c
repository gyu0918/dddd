/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:35:24 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/27 14:26:13 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len(long long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	num;
	int			i;

	num = n;
	i = ft_len(num);
	str = malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (NULL);
	str[i] = '\0';
	if (num == 0)
		str[0] = 48;
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[--i] = 48 + (num % 10);
		num /= 10;
	}
	return (str);
}
