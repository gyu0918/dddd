/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:11:45 by junggkim          #+#    #+#             */
/*   Updated: 2023/06/17 21:11:48 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

int check_last_eat_time(t_philo *philo)
{
    int result;

    pthread_mutex_lock(&philo->check->last_eat_time);
	result = philo->last_eat_time;
	pthread_mutex_unlock(&philo->check->last_eat_time);
    return (result);
}

int check_eat_count(t_philo *philo, t_check *check)
{
    int i;
    int result;

    i = -1;
    result = 0;
    while (++i < check->number_of_philosophers)
    {
		pthread_mutex_lock(&philo->check->eaten_num);
		result += philo[i].eaten_num;
		pthread_mutex_unlock(&philo->check->eaten_num);
	}
    return (result);
}

int die_check(t_philo *philo)    
{
	int	tmp;

	tmp = 0;
	pthread_mutex_lock(&philo->check->die_check);
	tmp = philo->check->die;
	pthread_mutex_unlock(&philo->check->die_check);
	if (tmp == 1)
		return (1);
	else
		return (0);
}
