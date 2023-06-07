/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:46:19 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/07 22:52:08 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *p)
{
	philo	*t;

	t = (philo *)p;
	pthread_mutex_lock(&t->mutex);
	printf("thread beggins\n");
	sleep(1);
	printf("thread ends\n");
	pthread_mutex_lock(&t->mutex);
	return (NULL);
}
void	threads_creation(philo *p)
{
	// (void)p;
	int	i;
	pthread_t t[p->p_nb];

	pthread_mutex_init(&p->mutex, NULL);
	i = 0;
	while (i < p->p_nb)
	{
		if ((i % p->p_nb) != 0)
		{
			if (pthread_create(&t[i], NULL, &routine, &p))
				put_error("ERROR 1\n");
			if (pthread_create(&t[i + 1], NULL, &routine, &p))
				put_error("ERROR 2\n");
			if (pthread_join(t[i], NULL))
				put_error("ERROR 3\n");
			if (pthread_join(t[i + 1], NULL))
				put_error("ERROR 4\n");
		}
		else
		{
			if (pthread_create(&t[i], NULL, &routine, &p))
				put_error("ERROR 5\n");
			if (pthread_create(&t[0], NULL, &routine, &p))
				put_error("ERROR 6\n");
			if (pthread_join(t[i], NULL))
				put_error("ERROR 7\n");
			if (pthread_join(t[0], NULL))
				put_error("ERROR 8\n");
		}	
		i++;
	}
	pthread_mutex_destroy(&p->mutex);
}

int main(int ac, char **av)
{
	philo p;

	if (ac == 4 || ac == 5)
	{
		parsing(av, &p);
		threads_creation(&p);
	}
}

