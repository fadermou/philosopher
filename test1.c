# include "philosopher.h"

unsigned long	get_time()
{
    struct timeval tv;

	gettimeofday(&tv, NULL);
	return(tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_sleep(unsigned long time)
{
	unsigned long time_now;

	time_now = get_time(); 
	while (get_time() - time_now < time)
		usleep(10);
}
pthread_mutex_t l;

void *routine()
{
	pthread_mutex_lock(&l);
	printf("usleep started\n");
	usleep(1000000);
	printf("usleep finished\n");
	pthread_mutex_unlock(&l);
	return (NULL);
}

void *routine2()
{
	pthread_mutex_lock(&l);
	printf("ft_sleep started\n");
	ft_sleep(1000000);
	printf("ft_sleep finished\n");
	pthread_mutex_unlock(&l);
	return (NULL);
}

int main()
{
	pthread_t t, t2;

	pthread_create(&t2, NULL, &routine2, NULL);
	pthread_create(&t, NULL, &routine, NULL);
	pthread_join(t, NULL);
	pthread_join(t2, NULL);
}