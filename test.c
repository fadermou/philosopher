
#include "philo.h"

	// int i = 0;

// void	*routine(void *p)
// {
// 	philo *t = (philo *)p;

// 	pthread_mutex_lock(&t->mutex);
// 	for (size_t i = 0; i < 1000000; i++)
// 		t->mails++;
// 	pthread_mutex_unlock(&t->mutex);
// 	return (NULL);
// }

// int main()
// {
// 	pthread_t t, t2;
// 	pthread_t t3, t4;
// 	philo p;
// 	p.mails = 0;

// 	pthread_mutex_init(&p.mutex, NULL);
// 	pthread_create(&t, NULL, &routine, &p);
// 	pthread_create(&t2, NULL, &routine, &p);
// 	pthread_create(&t3, NULL, &routine, &p);
// 	pthread_create(&t4, NULL, &routine, &p);
// 	pthread_join(t, NULL);
// 	pthread_join(t2, NULL);
// 	pthread_join(t3, NULL);
// 	pthread_join(t4, NULL);
// 	pthread_mutex_destroy(&p.mutex);
// 	printf("%d\n", p.mails);
// 	// pthread_join(t2, NULL);
// }

// int main()
// {
// 	int tab[5 / 2];
// 	int tab2[5 / 2];


// }