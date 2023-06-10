/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:29:30 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/10 22:24:54 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// void *routine(void *philo)
// {
// 	t_philo *ph;
// 	ph = (t_philo *)philo;
// 	while (1)
// 	{
// 		if (pthread_mutex_lock(ph->l_fork))
// 			printf("locking mutex's failed\n");
// 		else
// 			printf("philo numb [%d] has taken a left fork\n", ph->id);
// 		if (pthread_mutex_lock(ph->r_fork))
// 			printf("locking mutex's failed\n");
// 		else
// 			printf("philo numb [%d] has taken a left fork\n", ph->id);
// 		ph->last_meal = get_time();
// 		printf("%lu [%d] is eating\n", get_time(), ph->id);
// 		ft_sleep(ph->data->tm28);
// 		printf("-->here\n");
// 		if (pthread_mutex_unlock(ph->l_fork))
// 			printf("unlocking mutex's failed\n");
// 		if (pthread_mutex_unlock(ph->r_fork))
// 			printf("unlocking mutex's failed\n");
// 		else
// 		{
// 			printf("%lu [%d] is sleeping\n", get_time(), ph->id);
// 			ft_sleep(ph->data->tm2sl);
// 		}
// 	}
// 	return (NULL);
// }

void *routine(void *philo)
{
	t_philo *ph;

	ph = (t_philo *)philo;
	if (ph->id %  2)
		usleep(500);
	while (1)
	{
		pthread_mutex_lock(ph->l_fork);
		printf("philo numb [%d] has taken a left fork\n", ph->id);
		pthread_mutex_lock(ph->r_fork);
		printf("philo numb [%d] has taken a right fork\n", ph->id);
		ph->last_meal = get_time() - ph->data->start_time;
		printf("---->%lu\n", ph->last_meal);
		printf("philo numb [%d] is eating\n", ph->id);
		ft_sleep(ph->data->tm28);
		pthread_mutex_unlock(ph->l_fork);
		pthread_mutex_unlock(ph->r_fork);
		printf("philo num [%d] is sleeping\n", ph->id);
		ft_sleep(ph->data->tm2sl);
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_data data;
	pthread_t	t;
	int i;

	if (ac == 5 || ac == 6)
	{
		if (parsing(av, &data))
			return (1);
			i = 0;
			while (i < data.p_nb)
			{
				pthread_create(&t, NULL, &routine, &data.philo[i]);
				i += 2;
			}
			i = 1;
			while (i < data.p_nb)
			{
				pthread_create(&t, NULL, &routine, &data.philo[i]);
				i += 2;
			}
			while (1)
			{
				i = 0;
				while (i < data.p_nb)
				{
					if (check_death(&data.philo[i]))
						return (1);
					i++;
				}
			}
	}
	else
		write(2, "not enough arguments\n", 21);
}
