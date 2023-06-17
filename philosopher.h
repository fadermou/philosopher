#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
#include <pthread.h>

#define L_FORK 	1
#define R_FORK 	2
#define EAT 	3
#define SLEEP	4

typedef struct philo
{
	int id;
	int err;
	unsigned long last_meal;
	pthread_mutex_t *r_fork;
	pthread_mutex_t *l_fork;
	struct data *data;
}t_philo;

typedef	struct data
{
	int	p_nb;
	int	tm2sl;
	int	tm28;
	int	nb28;
	int	tm2di;
	unsigned long start_time;
	pthread_mutex_t *forks;
	t_philo *philo;
}	t_data;

int	parsing(char **av, t_data *data);
int	ft_atoi(char *str);
void	ft_sleep(unsigned long time);
unsigned long	get_time();
int	check_death(t_philo *philo);

#endif