/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:46:19 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/10 11:47:24 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void *routine(void *p)
// {
// 	philo	*t;

// 	t = (philo *)p;
// 	(void)p;
// 	printf("hh\n");
// // 	pthread_mutex_lock(&t->mutex);
// // 	// printf("thread beggins\n");
// // 	printf("philo number %d has teaken the a fork\n",t->i);
// // 	sleep(1);
// // 	printf("thread ends\n");
// // 	pthread_mutex_lock(&t->mutex);
// 	return (NULL);
// }

int	ft_philo(philo *p)
{
	while (1)
	{
		if (forks_creation(p))
			return (1);
		p->id = 0;
		while (p->id < p->p_nb)
		{
			if (threads_creation(p))
				return (1);
			if (mutex_creation(p))
				return (1);
			p->id++;
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	philo p;

	if (ac == 5 || ac == 6)
	{
		if (parsing(av, &p))
			return (1);
		if (ft_philo(&p))
			return 1;
	}
	else
		write(2, "not enough arguments\n", 21);
}
