# include <unistd.h>
# include <sys/time.h>

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
int main()
{
	printf("test2 started\n");
	ft_sleep(10);
	printf("test2 finished\n");
}


//DATA RACE