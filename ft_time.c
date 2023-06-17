/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:09:31 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/11 19:15:29 by fadermou         ###   ########.fr       */
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

	time = (get_time() - philo->data->start_time) - philo->last_meal;
	if (time > (unsigned long)philo->data->tm2di)
	{
		printf("philo num [%d] is dead\n", philo->id);
		return (1);
	}
	return (0);
}
