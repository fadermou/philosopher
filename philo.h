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

	int	i;
	int	p_nb;
	// pthread_mutex_t	forks[p_nb];
	int	tm2sl;
	int	tm28;
	int	nb28;
	int	tm2di;
	unsigned long *last_meal;
	pthread_mutex_t *philo;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	// int	mails;
}		philo;

unsigned long	get_time();
void			ft_sleep(unsigned long time);
void			taking_forks(philo *p);
int				parsing(char **av, philo *p);
int			mutex_creation(philo *p);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
void			put_error(char *str);
int				forks_creation(philo *p);
int				threads_creation(philo *p);

#endif

// void	threads_creation(philo *p)
// {
// 	// (void)p;
// 	pthread_t t[p->p_nb];

// 	while(numb)
// 	pthread_mutex_init(&p->mutex, NULL);
	
// 	p->i = 1;
// 	while (p->i <= p->p_nb)
// 	{
// 		if ((p->i % p->p_nb) != 0)
// 		{
// 		printf("here\n");
// 			printf("%d\n", p->i);
// 			if (pthread_create(&t[p->i], NULL, &routine, &p))
// 				put_error("ERROR 1\n");
// 			if (pthread_join(t[p->i], NULL))
// 				put_error("ERROR 3\n");
// 		p->i++;
// 		}
// 		else
// 		{
// 		printf("nd here\n");
// 			// if (pthread_create(&t[i], NULL, &routine, &p))
// 			// 	put_error("ERROR 5\n");
// 			// if (pthread_create(&t[0], NULL, &routine, &p))
// 			// 	put_error("ERROR 6\n");
// 			// if (pthread_join(t[i], NULL))
// 			// 	put_error("ERROR 7\n");
// 			// if (pthread_join(t[0], NULL))
// 			// 	put_error("ERROR 8\n");
// 			// break;
// 		}
// 	}
// 	pthread_mutex_destroy(&p->mutex);
// }