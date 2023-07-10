/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:55:28 by junggkim          #+#    #+#             */
/*   Updated: 2023/06/24 15:35:09 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_check
{
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_philosophers;
    int eat_count;
    int die;
    pthread_mutex_t *forks;
    pthread_mutex_t last_eat_time;
    pthread_mutex_t die_check;
    pthread_mutex_t print;
    pthread_mutex_t eaten_num;
}   t_check;

typedef struct s_philo
{
    int num;
    int left_fork;
    int right_fork;
    int eaten_num;
    long last_eat_time;
    long start_thread_time;
    pthread_t	thread;
    struct s_check  *check;
}   t_philo;

long    ft_get_time(void);
int     check_init(t_check *check, char **av, int ac);
int     philo_init(t_philo **philo, t_check *check);
int     mutex_init(t_check *check);
int     ft_atoi(const char *str);
int     ft_error(char *str);
void    free_all(t_philo **philo, t_check *check);
int     start_eating(t_philo *philo, t_check *check);
void    *ft_thread(void *ss);
void    ft_finish_check(t_philo *philo, t_check *check);
int     pass_time(t_philo *philo, int wait_time);
void    printf_mutex(t_philo *philo, int num, char *str);
int     die_check(t_philo *philo);
int     check_eat_count(t_philo *philo, t_check *check);
int     hard_coding(t_philo *philo);
int    fork_eating(t_philo *philo);
long    check_last_eat_time(t_philo *philo);

#endif
