/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:51:58 by junggkim          #+#    #+#             */
/*   Updated: 2022/11/23 19:29:32 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	a;
	long long	last_a;
	int			sign;

	a = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		last_a = a;
		a = a * 10 + (*str - '0');
		if ((a / 10 != last_a) && sign == 1)
			return (-1);
		else if ((a / 10 != last_a) && sign == -1)
			return (0);
		str++;
	}
	return (sign * a);
}
