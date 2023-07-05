/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:33:37 by fadermou          #+#    #+#             */
/*   Updated: 2023/06/23 23:39:37 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define L_FORK 1
# define R_FORK 2
# define EAT 3
# define SLEEP 4
# define DEATH 5

typedef struct philo
{
	int				id;
	unsigned long	last_meal;
	int				meals;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_t		t;
	struct data		*data;
}					t_philo;

typedef struct data
{
	int				p_nb;
	int				tm2sl;
	int				d;
	int				tm28;
	int				tm;
	int				nb28;
	int				meals;
	int				tm2di;
	int				flag;
	int				check;
	unsigned long	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	p_tm;
	pthread_mutex_t	p_meals;
	pthread_mutex_t	print;
	t_philo			*philo;
}					t_data;

void				print_it(int f, int id, t_data *data, char *str);
int					parsing(char **av, t_data *data, int ac);
int					ft_atoi(char *str);
int					args_are_digits(char **av);
void				ft_sleep(unsigned long time);
unsigned long		get_time(void);
int					check_death(t_philo *philo);

#endif
