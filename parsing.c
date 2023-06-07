/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:09:21 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/07 18:25:37 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	args_are_digits(char **av)
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
				put_error("there is an invalid number");
			j++;
		}
		i++;
	}
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

}

void	barintf(philo *p)
{
	printf("number of philo == %d\n",p->p_nb);
	printf("  time to die   == %d\n",p->tm2di);
	printf("  time to eat   ==%d\n",p->tm28);
	printf(" time to sleep  ==%d\n",p->tm2sl);
	// if (p->nb28)
		// printf(" number to eat  ==%d\n",p->nb28);
		
}

void	parsing(char **av, philo *p)
{
	args_are_digits(av);
	fill_my_struct(av, p);
	// barintf(p);
}