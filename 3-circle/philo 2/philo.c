/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junggkim <junggkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:55:19 by junggkim          #+#    #+#             */
/*   Updated: 2023/06/20 14:54:52 by junggkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
    t_check check;
    t_philo *philo;

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
/*


pass_time()
{
    while (time - time)
    {
        if (eat_time - 뭔 time    <= now_time -1)
            usleep(200);
    }
}

철학자 수가 짝수 일때는 그냥 하고 
          홀수 일때는     
                   |-> 또한 (먹는시간 > 자는 시간 ) usleep(50) 정도? 줘서 5번째 즉 홀수 마지막번째 철학자가 밥을 먹을수 있는 시간을 줘야 한다.


1. 230 200 
2. ~~~ 230 200 
3. 230 200
4. ~~~ 230 200
5. ~~~ ~~~ 230
*/
