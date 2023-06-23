/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:30:49 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/23 16:39:05 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_it(int f, int id, t_data *data, char *str)
{
	pthread_mutex_lock(&data->print);
	printf("%lu [%d] %s\n", get_time() - data->start_time, id, str);
	if (!f)
		pthread_mutex_unlock(&data->print);
}

int	args_are_digits(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
			{
				write(2, "there is an invalid character\n", 30);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	fill_each_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->p_nb)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		i++;
	}
	i = 0;
	while (i < data->p_nb)
	{
		data->philo[i].id = i + 1;
		data->philo[i].l_fork = &data->forks[i];
		data->philo[i].r_fork = &data->forks[(i + 1) % data->p_nb];
		data->philo[i].data = data;
		data->philo[i].last_meal = 0;
		data->philo[i].meals = 0;
		i++;
	}
	return (0);
}

int	fill_my_struct(char **av, t_data *data, int ac)
{
	data->start_time = get_time();
	data->p_nb = ft_atoi(av[1]);
	data->tm2di = ft_atoi(av[2]);
	data->tm28 = ft_atoi(av[3]);
	data->tm2sl = ft_atoi(av[4]);
	data->check = 0;
	data->meals = -1;
	if (ac == 6)
		data->meals = ft_atoi(av[5]);
	data->flag = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->p_nb);
	pthread_mutex_init(&data->p_tm, NULL);
	pthread_mutex_init(&data->p_meals, NULL);
	pthread_mutex_init(&data->print, NULL);
	data->philo = malloc(sizeof(t_philo) * data->p_nb);
	if (fill_each_philo(data))
		return (1);
	return (0);
}

int	parsing(char **av, t_data *data, int ac)
{
	if (args_are_digits(av))
		return (1);
	fill_my_struct(av, data, ac);
	return (0);
}
