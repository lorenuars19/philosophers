
#include "philo.h"

const char	*states[STATE_MAX] = {
		"THINKING",
		"REQUEST_L_FORK",
		"TOOK_L_FORK",
		"REQUEST_R_FORK",
		"TOOK_R_FORK",
		"READY_EATING",
		"EATING",
		"RELEASED_L_FORK",
		"RELEASED_R_FORK",
		"SLEEPING",
		"DEAD"};

// TODO remove debug
void	print_data(t_data *dat)
{
	int			i;

	printf("=== dat <%p>\n"
		"n_philo    %-6ld" "\n"
		"time_die   %-6llu" "\n"
		"time_eat   %-6llu" "\n"
		"time_sleep %-6llu" "\n"
		"max_meals  %-6ld" "\n",
		dat,
		dat->n_philo,
		dat->time_die,
		dat->time_eat,
		dat->time_sleep,
		dat->max_meals
		);
	i = 0;
	printf("- - - - - - - - -\n");
	while (i < dat->n_philo)
	{
		printf(
			"[i %3d] thread_id %#-16lx | time_last_meal %-16llu | fork %-16d | state %s"
			"\n",
			i, (unsigned long)dat->threads[i], dat->time_last_meal[i], dat->forks[i], states[dat->state[i]]);
		i++;
	}
	// printf("mutexes A %p DATA %p A %p PRINT %p\n",
	// 	&(dat->mutex_data), dat->mutex_data,
	// 	&(dat->mutex_print), dat->mutex_print);
}
