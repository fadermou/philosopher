/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:17:05 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/09 22:17:32 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void taking_forks(philo *p)
{
	while (1)
	{
		if (pthread_mutex_lock(&p->l_fork[p->id + 1]))
			write(2, "creating mutex's failed\n", 24);
		else
			printf("philo numb [%d] has taken a left fork\n", p->id);
		if (pthread_mutex_lock(&p->r_fork[p->id + 1]))
			write(2, "creating mutex's failed\n", 24);
		else
			printf("philo numb [%d] has raken a right fork\n", p->id);
		printf("philo num [%d] is eating\n", p->id);
		p->last_meal[p->id + 1] = get_time();
		ft_sleep(p->tm28);
		if (pthread_mutex_unlock(&p->l_fork[p->id + 1]))
			write(2, "Error\n", 6);
		else
		{
			printf("philo num [%d] is sleeping\n", p->id);
			ft_sleep(p->tm2sl);
		}
	}
}
