/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:46:19 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/08 18:05:13 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void *routine(void *p)
// {
// 	philo	*t;

// 	t = (philo *)p;
// 	pthread_mutex_lock(&t->mutex);
// 	// printf("thread beggins\n");
// 	printf("philo number %d has teaken the a fork\n",t->i);
// 	sleep(1);
// 	printf("thread ends\n");
// 	pthread_mutex_lock(&t->mutex);
// 	return (NULL);
// }
// void	threads_creation(philo *p)
// {
// 	// (void)p;
// 	pthread_t t[p->p_nb];

// 	while(numb)
// 	pthread_mutex_init(&p->mutex, NULL);
	
// 	p->i = 1;
// 	while (p->i <= p->p_nb)
// 	{
// 		if ((p->i % p->p_nb) != 0)
// 		{
// 		printf("here\n");
// 			printf("%d\n", p->i);
// 			if (pthread_create(&t[p->i], NULL, &routine, &p))
// 				put_error("ERROR 1\n");
// 			if (pthread_join(t[p->i], NULL))
// 				put_error("ERROR 3\n");
// 		p->i++;
// 		}
// 		else
// 		{
// 		printf("nd here\n");
// 			// if (pthread_create(&t[i], NULL, &routine, &p))
// 			// 	put_error("ERROR 5\n");
// 			// if (pthread_create(&t[0], NULL, &routine, &p))
// 			// 	put_error("ERROR 6\n");
// 			// if (pthread_join(t[i], NULL))
// 			// 	put_error("ERROR 7\n");
// 			// if (pthread_join(t[0], NULL))
// 			// 	put_error("ERROR 8\n");
// 			// break;
// 		}
// 	}
// 	pthread_mutex_destroy(&p->mutex);
// }

void mutex_creation(philo *p)
{
	int			i;

	p->fork = malloc(sizeof(pthread_mutex_t) * p->p_nb);
	p->l_fork = malloc(sizeof(pthread_mutex_t) * p->p_nb);
	p->r_fork = malloc(sizeof(pthread_mutex_t) * p->p_nb);
	i = 0;
	while (i < p->p_nb)
	{
		if (pthread_mutex_init(&p->fork[i], NULL))
			write(2, "Failed to create mutex\n", 22);
		else
			printf("mutex number [%d] has been created successfully\n", i);
		i++;
	}
	i = 0;
	while (i < p->p_nb)
	{
		p->r_fork[i] = p->fork[i];
		p->l_fork[i] = p->fork[(i + 1) % p->p_nb];
		i++;
	}
}

void	forks_creation(philo *p)
{
	mutex_creation(p);
}

int main(int ac, char **av)
{
	philo p;

	if (ac == 5 || ac == 6)
	{
		parsing(av, &p);
		forks_creation(&p);
	}
	else
		write(2, "not enough arguments\n", 21);
}

