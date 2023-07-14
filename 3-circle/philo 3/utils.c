/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:43:20 by junggkim          #+#    #+#             */
/*   Updated: 2023/06/24 13:48:13 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int hard_coding(t_philo *philo)
{
    printf("%ld 1 has taken a fork\n", philo[0].start_thread_time - ft_get_time());
    pass_time(philo, philo->check->time_to_die);
    printf("%ld 1 died\n", ft_get_time() - philo[0].start_thread_time);
    return (0);
}

void    printf_mutex(t_philo *philo, int num, char *str)
{
    long now_time;
    
    now_time = ft_get_time();   
    pthread_mutex_lock(&(philo->check->print));
    if (!die_check(philo))
        printf("%ld %d %s\n", now_time - philo->start_thread_time, num, str);
    pthread_mutex_unlock(&(philo->check->print));
}

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
	free(check->forks);
	check = NULL;
	free(*philo);
	philo = NULL;
}