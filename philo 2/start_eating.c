/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:19:44 by junggkim          #+#    #+#             */
/*   Updated: 2023/06/20 17:21:50 by junggkim         ###   ########.fr       */
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

int check_eat_count(t_philo *philo, t_check *check)
{
    int i;
    int result;

    i = -1;
    result = 0;
    while (++i < check->number_of_philosophers)
        result += philo[i].eaten_num;
    return (result);
}

/*void    change_die(t_philo *philo)
{
    pthread_mutex_lock(&philo->check->die_check);
    philo->check->die = 1;
    pthread_mutex_unlock(&philo->check->die_check);
}*/

int die_check(t_philo *philo)    
{
    int tmp;

	pthread_mutex_lock(&philo->check->die_check);
	tmp = philo->check->die;
    pthread_mutex_unlock(&philo->check->die_check);
    if (tmp == 1)
		return (1);
	else
		return (0);
}

void    pass_time(t_philo *philo, int wait_time)
{
	long	start_time;
	long	now_time;

	start_time = ft_get_time();
	while (!die_check(philo))
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
    
	while (!check->die)
	{
        if (check->eat_count != 0 && check_eat_count(philo, check) == check->eat_count)
			break ;
        i = -1;
        while (++i < check->number_of_philosophers)
        {
			now = ft_get_time();
            //printf("%ld ddd%d\n", now - philo[i].last_eat_time,check->time_to_die);
			if ((now - philo[i].last_eat_time) >= check->time_to_die)
			{
                pthread_mutex_lock(&check->die_check);
                check->die = 1;
                pthread_mutex_unlock(&check->die_check);
                printf_mutex(philo, i + 1, "died");
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
        usleep(100);
    while (!die_check(philo))
    {
        pthread_mutex_lock(&(philo->check->forks[philo->left_fork]));
        printf_mutex(philo, philo->num, "has taken a fork");
        pthread_mutex_lock(&(philo->check->forks[philo->right_fork]));
        printf_mutex(philo, philo->num, "has taken a fork");
        printf_mutex(philo, philo->num, "is eating");
        philo->last_eat_time = ft_get_time();
        philo->eaten_num++;
        pass_time(philo, philo->check->time_to_eat);
        pthread_mutex_unlock(&(philo->check->forks[philo->right_fork]));
        pthread_mutex_unlock(&(philo->check->forks[philo->left_fork]));
        if (philo->eaten_num == philo->check->eat_count)
        {
            philo->eaten_num++;
            break ;
        }
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