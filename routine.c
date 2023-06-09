/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:17:05 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/09 21:45:42 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void taking_forks(philo *p)
{
	while (1)
	{
		if (pthread_mutex_lock(&p->l_fork[p->i]))
			write(2, "creating mutex's failed\n", 24);
		else
			printf("philo numb [%d] has taken a left fork\n", p->i);
		if (pthread_mutex_lock(&p->r_fork[p->i]))
			write(2, "creating mutex's failed\n", 24);
		else
			printf("philo numb [%d] has raken a right fork\n", p->i);
		printf("philo num [%d] is eating\n", p->i);
		p->last_meal[p->i] = get_time();
		ft_sleep(p->tm28);
		if (pthread_mutex_unlock(&p->l_fork[p->i]))
			write(2, "Error\n", 6);
		else
		{
			printf("philo num [%d] is sleeping\n", p->i);
			ft_sleep(p->tm2sl);
		}
	}
}
