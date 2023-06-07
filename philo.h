#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
#include <pthread.h>

typedef struct philo
{
	int	p_nb;
	int	tm2sl;
	int	tm28;
	int	nb28;
	int	tm2di;
	pthread_mutex_t mutex;
	// int	mails;
}		philo;

void	parsing(char **av, philo *p);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	put_error(char *str);

#endif
