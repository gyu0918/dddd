/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:19:44 by junggkim          #+#    #+#             */
/*   Updated: 2023/06/24 15:36:53 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int fork_eating(t_philo *philo)
{
    pthread_mutex_lock(&(philo->check->forks[philo->left_fork]));
    printf_mutex(philo, philo->num, "has taken a fork");
    pthread_mutex_lock(&(philo->check->forks[philo->right_fork]));
    printf_mutex(philo, philo->num, "has taken a fork");
    printf_mutex(philo, philo->num, "is eating");
    pthread_mutex_lock(&philo->check->last_eat_time);
    philo->last_eat_time = ft_get_time();
    pthread_mutex_unlock(&philo->check->last_eat_time);
    pass_time(philo, philo->check->time_to_eat);
    pthread_mutex_lock(&philo->check->eaten_num);
    philo->eaten_num++;
    pthread_mutex_unlock(&philo->check->eaten_num);
    pthread_mutex_unlock(&(philo->check->forks[philo->right_fork]));
    pthread_mutex_unlock(&(philo->check->forks[philo->left_fork]));
    return (0);
}

int pass_time(t_philo *philo, int wait_time)
{
	long	start_time;
	long	now_time;

    //if (interval != 0)
       // usleep(interval + 100);
    if (die_check(philo))
        return (1);
	start_time = ft_get_time();
	while (!die_check(philo))
	{
		now_time = ft_get_time();
		if ((now_time - start_time) >= wait_time)
			break ;
		usleep(10);
	}
    return (0);
}

void    ft_finish_check(t_philo *philo, t_check *check)
{
	int     i;
	long    now;
    
	while (!die_check(philo))
	{
        if (check->eat_count != 0 && check_eat_count(philo, check)
            == check->eat_count * check->number_of_philosophers)
			break ;
        i = -1;
        while (++i < check->number_of_philosophers)
        {
			now = ft_get_time();
			if ((now - check_last_eat_time(&philo[i])) >= check->time_to_die)
			{
                printf_mutex(philo, i + 1, "died");
                pthread_mutex_lock(&philo->check->die_check);
                philo->check->die = 1;
                pthread_mutex_unlock(&philo->check->die_check);
				break ;
			}
		}
	}
}

void    *ft_thread(void *ss)
{
    t_philo *philo;

    philo = ss;
    if (philo->num % 2 == 0)
        usleep(200);
    while (!die_check(philo))
    {
        if (fork_eating(philo))
            break ;
       // if (pass_time(philo, philo->check->time_to_eat))
         //   break ;
        if (philo->eaten_num == philo->check->eat_count)
            break ;
        printf_mutex(philo, philo->num, "is sleeping");
        if (pass_time(philo, philo->check->time_to_sleep))
            break ;
        printf_mutex(philo, philo->num, "is thinking");
    }
    return (0);
}

int start_eating(t_philo *philo, t_check *check)
{
    int i;

    if (check->number_of_philosophers == 1)
    {
        i = hard_coding(philo);
        free_all(&philo, check);
        return (i);
    }
    i = -1;
    while (++i < check->number_of_philosophers)
    {
        pthread_mutex_lock(&check->last_eat_time);
		philo[i].last_eat_time = ft_get_time();
		pthread_mutex_unlock(&check->last_eat_time);
        if (pthread_create(&(philo[i].thread), NULL, ft_thread, &(philo[i])))
            return (1);
    }
    ft_finish_check(philo, check);
    i = -1;
    while (++i < check->number_of_philosophers)
        pthread_join(philo[i].thread, NULL);
    free_all(&philo, check);
    return (0);
}