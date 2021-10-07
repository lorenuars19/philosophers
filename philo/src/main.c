/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:32:08 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 13:13:00 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// TODO remove debug
void	print_data(t_data *dat)
{
	static char	*state_strings[STATE_MAX] = {"THINKING", "EATING", "SLEEPING", "DEAD", "FINISHED"};
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
			i, (unsigned long)dat->threads[i], dat->time_last_meal[i], dat->forks[i], state_strings[dat->state[i]]);
		i++;
	}
	printf("mutexes A %p DATA %p A %p PRINT %p\n", &(dat->mutex_data),dat->mutex_data, &(dat->mutex_print), dat->mutex_print);

}

static int	print_usage(char *prog)
{
	printf("=== Usage ===\n"
			" %s [number_of_philo] [time_to_die(ms)]"
			" [time_to_eat(ms)] [time_to_sleep(ms)]"
			" [maximum_number_of_meals (optional)] \n=============\n",
			prog);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	dat;

	printf("=== PHILO ===\n");
	if (!(argc == 5 || argc == 6))
	{
		print_usage(argv[0]);
		return (1);
	}
	if (init_data(&dat, argc, argv))
	{
		print_usage(argv[0]);
		return (1);
	}
PDAT(main before spawn_philos, &dat)
	if (spawn_philos(&dat))
	{
		return (1);
	}
PDAT(main before manage_threads, &dat); // TODO remove debug
	if (manage_threads(&dat))
	{
		return (1);
	}
PDAT(main before join_and_destroy, &dat); // TODO remove debug
	if (join_and_destroy(&dat))
	{
		return (1);
	}
PDAT(main END, &dat); // TODO remove debug
	return (0);
}
