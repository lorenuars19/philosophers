/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:51:29 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/07 10:04:02 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo_data(t_data *dat, int i)
{
	dat->phi_arr[i].thread = NULL;
	if (pthread_mutex_init(&(dat->phi_arr[i].fork), NULL))
		return (1);
	dat->phi_arr[i].r_fork = &(dat->phi_arr[i].fork);
	if (i > 0)
		dat->phi_arr[i].l_fork = dat->phi_arr[i - 1].r_fork;
	else if (i == 0)
		dat->phi_arr[i].l_fork = dat->phi_arr[dat->n_philo - 1].r_fork;
	dat->phi_arr[i].time_die = dat->time_die;
	dat->phi_arr[i].time_eat = dat->time_eat;
	dat->phi_arr[i].time_sleep = dat->time_sleep;
	dat->phi_arr[i].max_meals = dat->max_meals;
	dat->phi_arr[i].n_philo = dat->n_philo;
	dat->phi_arr[i].meals = 0;
	dat->phi_arr[i].id = i;
	return (0);
}

int	spawn_threads(t_data *dat)
{
	int			i;

	i = 0;
	while (i < dat->n_philo)
	{
		init_philo_data(dat, i);
		i++;
	}
	dat->phi_arr[0].l_fork = dat->phi_arr[dat->n_philo - 1].r_fork;
	i = 0;
	while (i < dat->n_philo)
	{
		if (pthread_create(&(dat->phi_arr[i].thread), NULL,
				philo_thread, (void*) &(dat->phi_arr[i])))
		{
			return (1);
		}
		i++;
	}
	check_death(dat);
	return (0);
}
