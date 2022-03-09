/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:12:44 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/08 13:54:49 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutexes(t_data *dat)
{
	if (pthread_mutex_init(&(dat->mutex), NULL))
	{
		return (1);
	}
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

static int	init_arrays(t_data *dat)
{
	int	i;

	dat->phi_arr = malloc((sizeof (t_phil_dat)) * dat->n_philo);
	if (!dat->phi_arr)
	{
		free(dat->phi_arr);
		return (1);
	}
	i = 0;
	while (i < dat->n_philo)
	{
		if (pthread_mutex_init(&(dat->phi_arr[i].fork), NULL))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_data(t_data *dat, int argc, char *argv[])
{
	memset(dat, 0, sizeof(*dat));
	if (parse_args(dat, argc, argv))
	{
		return (1);
	}
	if (dat->n_philo <= 0
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
