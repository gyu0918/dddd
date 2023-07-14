/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:43:20 by junggkim          #+#    #+#             */
/*   Updated: 2023/06/15 05:04:23 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int	ft_error(char *str)
{
	printf("%s\n", str);
	return (0);
}

void	free_all(t_philo **philo, t_check *check)
{
	int	i;
	int	j;

	i = 0;
	while (i < check->number_of_philosophers)
	{
		free(philo[i]);
		i++;
	}
	philo = NULL;
	j = 0;
	while (j < i)
	{
		free(&(check->forks[j]));
		j++;
	}
	check = NULL;
}