/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:29:30 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/22 16:50:20 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// void	print_it(int i, int id, t_data *data)
// {
// 	unsigned long	time;

// 	time = get_time() - data->start_time;
// 	// lock_print
// 	if (i == L_FORK)
// 	{
// 		printf("%lu [%d] has taken a left fork\n", time, id);
// 	}
// 	// unlock_print
// 	if (i == R_FORK)
// 		printf("%lu [%d] has taken a right fork\n", time, id);
// 	if (i == EAT)
// 		printf("%lu [%d] is eating\n", time, id);
// 	if (i == SLEEP)
// 		printf("%lu [%d] is sleeping\n", time, id);
// 	if (i == DEATH)
// 		printf("%lu [%d] is dead\n", time, id);
// }

void	print_it(int f, int id, t_data *data, char *str)
{
	unsigned long	time;
	// (void)f;

	// lock_print
	pthread_mutex_lock(data->death);
	pthread_mutex_lock(data->print);
	time = get_time() - data->start_time;
	pthread_mutex_unlock(data->print);
	printf("%lu [%d] %s\n", time, id, str);
	if (!f)
		pthread_mutex_unlock(data->death);
}

// void	*routine(void *philo)
// {
// 	t_philo	*ph;
// 	ph = (t_philo *)philo;
// 	if (ph->id % 2)
// 		usleep(50);
// 	while (1)
// 	{
// 		printf("herererere=====-----\n");
// 		(pthread_mutex_lock(ph->l_fork));
// 			// break ;
// 		print_it(0, ph->id, ph->data, "has taken a left fork");
// 		(pthread_mutex_unlock(ph->l_fork));
// 		(pthread_mutex_lock(ph->r_fork));
// 			// break ;
// 		print_it(0, ph->id, ph->data, "has taken a right fork");
// 		(pthread_mutex_unlock(ph->r_fork));
// 		pthread_mutex_lock(ph->data->p_tm);
// 		ph->last_meal = get_time() - ph->data->start_time;
// 		print_it(0, ph->id, ph->data, "is eating");
// 		pthread_mutex_unlock(ph->data->p_tm);
// 		ft_sleep(ph->data->tm28);
// 			// break ;
// 			// break ;
// 		print_it(0, ph->id, ph->data, "is sleeping");
// 		ft_sleep(ph->data->tm2sl);
// 	}
// 	// ph->err = 1;
// 	return (NULL);
// }


void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->id %  2)
		usleep(10);
	while (1)
	{
		pthread_mutex_lock(ph->l_fork);
		print_it(0, ph->id, ph->data, "has taken a left fork");
		pthread_mutex_unlock(ph->l_fork);
		pthread_mutex_lock(ph->r_fork);
		print_it(0, ph->id, ph->data, "has taken a right fork");
		pthread_mutex_unlock(ph->r_fork);
		// pthread_mutex_lock(ph->data->p_tm2);
		ph->last_meal = get_time() - ph->data->start_time;
		// pthread_mutex_unlock(ph->data->p_tm2);
		print_it(0, ph->id, ph->data, "is eating");
		ft_sleep(ph->data->tm28);
		print_it(0, ph->id, ph->data, "is sleeping");
		ft_sleep(ph->data->tm2sl);
		print_it(0, ph->id, ph->data, "is thinking");
	}
	return (NULL);
}


int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	t;
	int			i;

	if (ac == 5 || ac == 6)
	{
		if (parsing(av, &data))
			return (1);
		i = 0;
		while (i < data.p_nb)
		{
			pthread_create(&t, NULL, &routine, &data.philo[i]);
			i++;
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

// 5 philos 