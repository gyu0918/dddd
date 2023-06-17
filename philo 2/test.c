/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejikim <sejikim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:28:49 by sejikim           #+#    #+#             */
/*   Updated: 2023/06/15 16:52:46 by sejikim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// init.c

long	ft_get_time(void)
{
	long			result;
	struct timeval	time;

	gettimeofday(&time, NULL);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}

int	check_init(t_check *check, char **av, int ac)
{
	check->number_of_philosophers = ft_atoi(av[1]);
	check->time_to_die = ft_atoi(av[2]);
	check->time_to_eat = ft_atoi(av[3]);
	check->time_to_sleep = ft_atoi(av[4]);
	check->eat_count = 0;
	check->end = 1;
	if (ac == 6)
	{
		check->eat_count = ft_atoi(av[5]);
		if (check->eat_count <= 0)
			return (1);
	}
	if (check->number_of_philosophers <= 0 || check->time_to_die < 0 ||\
	check->time_to_eat < 0 || check->time_to_sleep < 0)
		return (1);
	return (0);
}

int	philo_init(t_philo **philo, t_check *check)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * check->number_of_philosophers);
	if (!philo)
		return (1);
	printf("%d\n", check->number_of_philosophers);
	i = 0;
	while (i < check->number_of_philosophers)
	{
		((*philo)[i]).num = i + 1;
		((*philo)[i]).left_fork = i;
		((*philo)[i]).right_fork = (i + 1) % check->number_of_philosophers;
		((*philo)[i]).eaten_num = 0;
		((*philo)[i]).last_eat_time = 0;
		((*philo)[i]).start_thread_time = ft_get_time();
		((*philo)[i]).check = check;
		i++;
		printf("%d\n", i);
	}
	return (0);
}

int	mutex_init(t_check *check)
{
	int	i;

	check->forks = malloc(sizeof(pthread_mutex_t) * \
	check->number_of_philosophers);
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

// start_eating.c

void	printf_mutex(t_philo *philo, int num, char *str)
{
	long	now_time;

	now_time = ft_get_time();
	pthread_mutex_lock(&(philo->check->print));
	if (philo->check->end)
		printf("%ld %d %s\n", now_time - philo->start_thread_time, num, str);
	pthread_mutex_unlock(&(philo->check->print));
}


void	pass_time(t_philo *philo, int wait_time)
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

void	ft_finish_check(t_philo *philo, t_check *check)
{
	int		i;
	long	now;
	int		eat;

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

void	*ft_thread(void *ss)
{
	t_philo	*philo;

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

int	start_eating(t_philo *philo, t_check *check)
{
	int	i;

	if (check->number_of_philosophers == 1)
	{
		printf("%ld 1 has taken a fork\n", ft_get_time());
		pass_time(philo, philo->check->time_to_eat);
		printf("%ld 1 died\n", ft_get_time());
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

// utils.c

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

// main.c

#include <stdlib.h>

int	main(void)
{
	t_check	check;
	t_philo	*philo;
	int		ac;
	char	**av;

	ac = 5;
	av = malloc(sizeof(char) * 5);
	av[1] = "5";
	av[2] = "800";
	av[3] = "200";
	av[4] = "200";

	if (ac != 5 && ac != 6)
		return (ft_error("ac error!!\n"));
	if (check_init(&check, av, ac))
		return (ft_error("check_init error!!\n"));
	if (mutex_init(&check))
	{
		free(check.forks);
		return (ft_error("mutex error!!\n"));
	}
	if (philo_init(&philo, &check))
	{
		free_all(&philo, &check);
		return (ft_error("philo_init error!!\n"));
	}
	if (start_eating(philo, &check))
	{
		free_all(&philo, &check);
		return (ft_error("start_eating error!!\n"));
	}
	return (0);
}
