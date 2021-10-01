/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:32:08 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/01 14:53:32 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_data *dat)
{
	if (pthread_mutex_init(&(dat->mutex_fork[0]), NULL))
	{
		return (1);
	}
	if (pthread_mutex_init(&(dat->mutex_fork[1]), NULL))
	{
		return (1);
	}
	if (pthread_mutex_init(&(dat->mutex_print), NULL))
	{
		return (1);
	}
	if (pthread_mutex_init(&(dat->mutex_data), NULL))
	{
		return (1);
	}
	return (0);
}

int	init_data(t_data *dat, int argc, char *argv[])
{
	int	i;

	dat->n_philo = str_to_uns(argv[1]);
	dat->time_die = str_to_uns(argv[2]);
	dat->time_eat = str_to_uns(argv[3]);
	dat->time_sleep = str_to_uns(argv[4]);
	dat->max_meals = 0;
	if (argc == 6)
		dat->max_meals = str_to_uns(argv[5]);
	i = 0;
	if (dat->n_philo <= 0 || dat->n_philo >= THREADS_MAX || dat->time_die <= 0
		|| dat->time_eat <= 0 || dat->time_sleep <= 0)
	{
		return (1);
	}
	while (i < dat->n_philo)
	{
		dat->threads[i] = 0;
		dat->time_until_death[i] = 0;
		dat->time_last_meal[i] = 0;
		dat->forks[i] = FORK_AVAILABLE;
		dat->state[i] = STATE_THINKING;
		i++;
	}
	if (init_mutexes(dat))
	{
		return (1);
	}

	return (0);
}

static int	join_and_destroy(t_data *dat)
{
	int	i;

	i = 0;
	while (i <= dat->n_philo)
	{
		if (pthread_join(dat->threads[i], NULL))
		{
			return (1);
		}
		dat->threads[i] = (pthread_t) NULL;
		i++;
	}
	if (pthread_mutex_destroy(&(dat->mutex_fork[0])))
	{
		if (pthread_mutex_destroy(&(dat->mutex_fork[i])))
		{
			return (1);
		}
		i++;
	}
	if (pthread_mutex_destroy(&(dat->mutex_fork[1])))
	{
		return (1);
	}

	return (0);
}

// TODO remove debug
void	print_data(t_data *dat)
{
	static char	*state_strings[STATE_N] = {"THINKING", "EATING", "SLEEPING", "DEAD"};
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
	while (i < dat->n_philo)
	{
		printf(
			"[i %3d] thread_id %#-16lx | time_until_death %-16llu | time_last_meal %-16llu | fork %-16d | state %s"
			"\n",
			i, (unsigned long)dat->threads[i], dat->time_until_death[i], dat->time_last_meal[i], dat->forks[i], state_strings[dat->state[i]]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_data	dat;

	printf("=============\n=== PHILO ===\n=============\n");
	if (!(argc == 5 || argc == 6))
	{
		printf("=== Usage ===\n"
			" %s [number_of_philo] [time_to_die(ms)]"
			" [time_to_eat(ms)] [time_to_sleep(ms)]"
			" [maximum_number_of_meals (optional)] \n=============\n",
			argv[0]);
		return (1);
	}
	if (init_data(&dat, argc, argv))
	{
		return (1);
	}
	if (spawn_philos(&dat))
	{
		return (1);
	}
PDAT(main, &dat); // TODO remove debug
	if (manage_threads(&dat))
	{
		return (1);
	}
	if (join_and_destroy(&dat))
	{
		return (1);
	}
	return (0);
}
