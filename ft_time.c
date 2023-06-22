/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:09:31 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/22 16:53:18 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

unsigned long	get_time()
{
    struct timeval tv;

	gettimeofday(&tv, NULL);
	return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_sleep(unsigned long time)
{
	unsigned long time_now;

	time_now = get_time(); 
	while (get_time() - time_now < time)
		usleep(10);
}

int	check_death(t_philo *philo)
{
	unsigned long time;

	// pthread_mutex_lock(philo->data->death);
	// pthread_mutex_lock(philo->data->hihi);
	pthread_mutex_lock(philo->data->p_tm);
	// time = get_time() - philo->data->start_time - philo->last_meal;
	pthread_mutex_unlock(philo->data->p_tm);
	if (time > (unsigned long)philo->data->tm2di)
	// pthread_mutex_unlock(philo->data->hihi);
	{
		philo->data->flag = 1;
		print_it(1, philo->id, philo->data, "is dead");
		return (1);
	}
	// if (!philo->data->flag)
	// {	
	// 	// pthread_mutex_unlock(philo->data->death);
	// 	return (1);
	// }
	return (0);
}
