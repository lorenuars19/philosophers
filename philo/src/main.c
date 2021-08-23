#include "philo.h"

int	counter;

void	*print_msg(void *ptr)
{
	t_tdat	*tdat;

	tdat = (t_tdat *)ptr;

	pthread_mutex_lock(tdat->mutex_ptr);

	printf("Thread %ld Num %d counter %d Mutex <%p>\n", pthread_self(),\
						tdat->num, tdat->counter, tdat->mutex_ptr);

	tdat->counter++;
	pthread_mutex_unlock(tdat->mutex_ptr);
	return (ptr);
}

int main(int argc, char *argv[])
{
	int		i;
	t_pdat	p;
	t_tdat	tdat;

	(void)argc;
	(void)argv;

	pthread_mutex_init(&(p.mutex), NULL);
	i = 0;
	tdat.counter = 0;
	while (i < THREADS_MAX)
	{
		tdat = (t_tdat){i, &(p.mutex), tdat.counter};
		p.returns[i] = pthread_create(&(p.threads[i]), NULL,
										print_msg, (void *)&tdat);
		i++;
	}
	i = 0;
	while (i < THREADS_MAX)
	{
		pthread_join(p.threads[i], NULL);
		i++;
	}

	printf("counter %d\n", tdat.counter);

	i = 0;
	printf("=== return values ===\n");
	while (i < THREADS_MAX)
	{
		printf("[i %d %d] ", i, p.returns[i]);
		i++;
	}


}
