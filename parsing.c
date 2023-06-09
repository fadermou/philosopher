/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:09:21 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/09 20:56:45 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_are_digits(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while(av[i][j])
		{
			if (av[i][j] < 48 || av[i][j] > 57)
			{
				write(2, "there is an invalid character\n", 30);
				return (1);
			}
				// put_error("there is an invalid number");
			j++;
		}
		i++;
	}
	return (0);
}

void	fill_my_struct(char **av, philo *p)
{

	p->p_nb = ft_atoi(av[1]);
	p->tm2di = ft_atoi(av[2]);
	p->tm28 = ft_atoi(av[3]);
	p->tm2sl = ft_atoi(av[4]);
	// if (av[5])
	// 	p->nb28 = ft_atoi(av[5]);
	// else
	// 	p->nb28 = 0;
	p->philo = malloc(sizeof(pthread_mutex_t) * p->p_nb);
	p->l_fork = malloc(sizeof(pthread_mutex_t) * p->p_nb);
	p->r_fork = malloc(sizeof(pthread_mutex_t) * p->p_nb);
	p->last_meal = malloc(sizeof(unsigned long) * p->p_nb);

}

void	barintf(philo *p)
{
	printf("number of philo == %d\n",p->p_nb);
	printf("  time to die   == %d\n",p->tm2di);
	printf("  time to eat   == %d\n",p->tm28);
	printf(" time to sleep  == %d\n",p->tm2sl);
	// if (p->nb28)
		// printf(" number to eat  ==%d\n",p->nb28);
}

int	parsing(char **av, philo *p)
{
	if (args_are_digits(av))
		return (1);
	fill_my_struct(av, p);
	// barintf(p);
	return (0);
}