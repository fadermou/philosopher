/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:29:30 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/11 19:18:12 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_it(int i, int id, t_data *data)
{
	unsigned long time;

	time = get_time() - data->start_time;
	if (i == L_FORK)
		printf("%lu [%d] has taken a left fork\n", time, id);
	if (i == R_FORK)
		printf("%lu [%d] has taken a right fork\n", time, id);
	if (i == EAT)
		printf("%lu [%d] is eating\n", time, id);
	if (i == SLEEP)
		printf("%lu [%d] is sleeping\n", time, id);
		
}

void *routine(void *philo)
{
	t_philo *ph;

	ph = (t_philo *)philo;
	// if (ph->id %  2)
	// 	usleep(500);
	while (1)
	{
		if (pthread_mutex_lock(ph->l_fork))
			break;
		print_it(L_FORK, ph->id, ph->data);
		if (pthread_mutex_lock(ph->r_fork))
			break;
		print_it(R_FORK, ph->id, ph->data);
		ph->last_meal = get_time() - ph->data->start_time;
		print_it(EAT, ph->id, ph->data);
		ft_sleep(ph->data->tm28);
		if (pthread_mutex_unlock(ph->l_fork))
			break;
		if (pthread_mutex_unlock(ph->r_fork))
			break;
		print_it(SLEEP, ph->id, ph->data);
		ft_sleep(ph->data->tm2sl);
	}
	ph->err = 1;
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
