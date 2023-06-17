/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:49:27 by junggkim          #+#    #+#             */
/*   Updated: 2023/06/15 04:59:16 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long ft_get_time(void)
{
    long result;
    struct timeval time;
    
    gettimeofday(&time, NULL);
    result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    return (result);
}

int check_init(t_check *check, char **av, int ac)
{
    check->number_of_philosophers = ft_atoi(av[1]);
    check->time_to_die = ft_atoi(av[2]);
    check->time_to_eat = ft_atoi(av[3]);
    check->time_to_sleep = ft_atoi(av[4]);
    check->eat_count = 0;
    check->die = 0;
    if (ac == 6)
    {
        check->eat_count = ft_atoi(av[5]);
        if (check->eat_count <= 0)//0번먹으면 종료되는걸 여기서 판별!
            return (1);
    }
    if (check->number_of_philosophers <= 0 || check->time_to_die < 0 || check->time_to_eat < 0
        || check->time_to_sleep < 0)
        return (1);
    return (0);
}

int philo_init(t_philo **philo, t_check *check)
{
    int i;

    *philo = malloc(sizeof(t_philo) * check->number_of_philosophers);
    if (!philo)
        return (1);
    printf("%d\n", check->number_of_philosophers);
    i = 0;
    while (i < check->number_of_philosophers)
    {
        (*philo)[i].num = i + 1;
        (*philo)[i].left_fork = i;
        (*philo)[i].right_fork = (i + 1) % check->number_of_philosophers;
        (*philo)[i].eaten_num = 0;
        (*philo)[i].last_eat_time = 0;
        (*philo)[i].start_thread_time = ft_get_time();
        (*philo)[i].check = check;
        i++;
    }
    return (0);
}

int mutex_init(t_check *check)
{
    int i;

    check->forks = malloc(sizeof(pthread_mutex_t) * check->number_of_philosophers);
    if (!(check->forks))
        return (1);
    i = -1;
    while (++i < check->number_of_philosophers)
    {
        if (pthread_mutex_init(&(check->forks[i]), NULL))
            return (1);
    }
    return (0);
}