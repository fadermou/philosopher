/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:29:30 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/22 22:19:21 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_it(int f, int id, t_data *data, char *str)
{
	// unsigned long	time;
	// (void)f;

	// lock_print
	pthread_mutex_lock(&data->print);
	// time = get_time() - data->start_time;
	printf("%lu [%d] %s\n", get_time() - data->start_time, id, str);
	if (!f)
		pthread_mutex_unlock(&data->print);
}

void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->id % 2)
		usleep(500);
	while (1)
	{
		pthread_mutex_lock(ph->l_fork);
		print_it(0, ph->id, ph->data, "has taken a left fork");
		pthread_mutex_lock(ph->r_fork);
		print_it(0, ph->id, ph->data, "has taken a right fork");
		pthread_mutex_lock(&ph->data->p_tm);
		ph->last_meal = get_time() - ph->data->start_time;
		pthread_mutex_unlock(&ph->data->p_tm);
		print_it(0, ph->id, ph->data, "is eating");
		ft_sleep(ph->data->tm28);
		pthread_mutex_unlock(ph->l_fork);
		pthread_mutex_unlock(ph->r_fork);
		print_it(0, ph->id, ph->data, "is sleeping");
		ft_sleep(ph->data->tm2sl);
		print_it(0, ph->id, ph->data, "is thinking");
	}
	return (NULL);
}


int	main(int ac, char **av)
{
	t_data		*data;
	int			i;

	data = malloc(sizeof(t_data));
	if (ac == 5 || ac == 6)
	{
		if (parsing(av, data))
			return (1);
		i = 0;
		while (i < data->p_nb)
		{
			pthread_create(&data->philo[i].t, NULL, &routine, &data->philo[i]);
			pthread_detach(data->philo[i].t);
			i++;
		}
		i = 0;
		while (i < data->p_nb)
		{
			pthread_join(data->philo[i].t, NULL);
			i++;
		}
		while (1)
		{
			i = 0;
			while (i < data->p_nb)
			{
				if (check_death(&data->philo[i]))
					return (1);
				i++;
			}
		}
	}
	else
		write(2, "not enough arguments\n", 21);
}

// 5 philos 