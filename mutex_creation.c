/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:30:08 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/09 22:07:34 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p)
{
	philo	*t;

	t = (philo *)p;
	taking_forks(t);
	return (NULL);
}

int	threads_creation(philo *p) 
{
	pthread_t	t;

	if (pthread_create(&t, NULL, &routine, p))
		return (1);
	if (pthread_join(t, NULL))
		return (1);
	return (0);
}

int forks_creation(philo *p)
{
	int			i;

	i = 0;
	while (i < p->p_nb)
	{
		if (pthread_mutex_init(&p->philo[i], NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < p->p_nb)
	{
		p->r_fork[i] = p->philo[i];
		p->l_fork[i] = p->philo[(i + 1) % p->p_nb];
		i++;
	}
	return (0);
}

int	check_death(philo p)
{
	int j;

	j = 0;
	while (j < p.p_nb)
	{
		if (get_time() - p.last_meal[j] > (unsigned long)p.tm2di)
		{
			printf("philo num [%d] is dead\n", p.i);
			// exit(1);
			return (1);
		}
		j++;
	}
	return (0);
}

int	mutex_creation(philo *p)
{
	// int f;

	// f = 0;
	// if (forks_creation(p))
	// 	return (1);
	// p->i = 0;
	// while (p->i < p->p_nb)
	// {
	// 	if (threads_creation(p))// in main
	// 		return (1);
	// 	p->i++;
	// }
	while (1)
	{
		if (check_death(*p))
			return (1);
	}
	return (0);
}
