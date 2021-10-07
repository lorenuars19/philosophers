/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:12:44 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 15:04:21 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutexes(t_data *dat)
{
	int	i;

	i = 0;
	while (i < dat->n_philo)
	{
		if (pthread_mutex_init(&(dat->mutex_fork[i]), NULL))
		{
			return (1);
		}
		i++;
	}
	if (pthread_mutex_init(&(dat->mutex_data), NULL))
	{
		return (1);
	}
	dat->check_data = MUTEX_FREE;
	if (pthread_mutex_init(&(dat->mutex_print), NULL))
	{
		return (1);
	}
	dat->check_print = MUTEX_FREE;
	return (0);
}

static int	parse_args(t_data *dat, int argc, char *argv[])
{
	t_uns	num;

	if (str_to_uns(argv[1], &num))
		return (1);
	dat->n_philo = num;
	if (str_to_uns(argv[2], &num))
		return (1);
	dat->time_die = num;
	if (str_to_uns(argv[3], &num))
		return (1);
	dat->time_eat = num;
	if (str_to_uns(argv[4], &num))
		return (1);
	dat->time_sleep = num;
	if (argc == 6)
	{
		if (str_to_uns(argv[5], &num))
		{
			return (1);
		}
		dat->max_meals = num;
	}
	return (0);
}

static	void	init_arrays(t_data *dat)
{
	int	i;

	i = 0;
	while (i < dat->n_philo)
	{
		dat->threads[i] = 0;
		dat->time_last_meal[i] = 0;
		dat->meals_consumed[i] = 0;
		dat->forks[i] = FORK_AVAILABLE;
		dat->state[i] = STATE_THINKING;
		i++;
	}
}

int	init_data(t_data *dat, int argc, char *argv[])
{
	memset(dat, 0, sizeof(*dat));
	if (parse_args(dat, argc, argv))
	{
		return (1);
	}
	if (dat->n_philo <= 0 || dat->n_philo >= THREADS_MAX
		|| dat->time_die <= 0 || dat->time_eat <= 0 || dat->time_sleep <= 0)
	{
		return (1);
	}
	init_arrays(dat);
	if (init_mutexes(dat))
	{
		return (1);
	}
	return (0);
}
