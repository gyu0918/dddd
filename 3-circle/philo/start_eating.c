/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:19:44 by junggkim          #+#    #+#             */
/*   Updated: 2023/06/15 05:03:12 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    printf_mutex(t_philo *philo, int num, char *str)
{
    long now_time;
    
    now_time = ft_get_time();   
    pthread_mutex_lock(&(philo->check->print));
    if (philo->check->end)
        printf("%ld %d %s\n", now_time - philo->start_thread_time, num, str);
    pthread_mutex_unlock(&(philo->check->print));
}


void    pass_time(t_philo *philo, int wait_time)
{
	long	start_time;
	long	now_time;

	start_time = ft_get_time();
	while (philo->check->end)
	{
		now_time = ft_get_time();
		if ((now_time - start_time) >= wait_time)
			break ;
		usleep(10);
	}
}

void    ft_finish_check(t_philo *philo, t_check *check)
{
	int     i;
	long    now;
    int     eat;
    
	while (check->end)
	{
        eat = 0;
		i = -1;
		while (++i < check->number_of_philosophers)
		{
            eat += philo[i].eaten_num;
            if ((check->eat_count != 0)
                && (eat == check->eat_count * check->number_of_philosophers))
            {
                check->end = 0;
			    break ;
            }
			now = ft_get_time();
			if ((now - philo[i].last_eat_time) >= check->time_to_die)
			{
                check->end = 0;
                printf_mutex(philo, i, "died");
				break ;
			}
		}
	}
}

void    *ft_thread(void *ss)
{
    t_philo *philo;

    philo = ss;
    if (philo->num % 2)
        usleep(100);
    while (philo->check->end)
    {
        pthread_mutex_lock(&(philo->check->forks[philo->left_fork]));
        printf_mutex(philo, philo->num, "has taken a fork");
        pthread_mutex_lock(&(philo->check->forks[philo->left_fork]));
        printf_mutex(philo, philo->num, "has taken a fork");
        printf_mutex(philo, philo->num, "is eating");
        philo->last_eat_time = ft_get_time();
        philo->eaten_num++;
        pass_time(philo, philo->check->time_to_eat);
        pthread_mutex_unlock(&(philo->check->forks[philo->right_fork]));
        pthread_mutex_unlock(&(philo->check->forks[philo->left_fork]));
        if (philo->eaten_num == philo->check->eat_count)
            break ;
        printf_mutex(philo, philo->num, "is sleeping");
        pass_time(philo, philo->check->time_to_eat);
        printf_mutex(philo, philo->num, "is thinking");
    }
    return (0);
}

int start_eating(t_philo *philo, t_check *check)
{
    int i;

    if (check->number_of_philosophers == 1)
    {
        printf("%ld 1 has taken a fork\n", philo[0].start_thread_time - ft_get_time());
        pass_time(philo, philo->check->time_to_die);
        printf("%ld 1 died\n", ft_get_time() - philo[0].start_thread_time);
        free_all(&philo, check);
        return (0);
    }
    i = -1;
    while (++i < check->number_of_philosophers)
    {
        philo[i].start_thread_time = ft_get_time();
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
 