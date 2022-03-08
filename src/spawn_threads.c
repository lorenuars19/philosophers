/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:51:29 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/08 13:54:49 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_philo_data(t_data *dat, t_phil_dat *pda, int i)
{
	pda->thread = NULL;
	pda->time_die = dat->time_die;
	pda->time_eat = dat->time_eat;
	pda->time_sleep = dat->time_sleep;
	pda->max_meals = dat->max_meals;
	pda->n_philo = dat->n_philo;
	pda->meals = 0;
	pda->last_meal = 0;
	pda->id = i;
	pda->data = dat;
	pda->mutex = &(dat->mutex);
	pda->l_fork = &(pda->fork);
	if (i > 0)
	{
		pda->r_fork = dat->phi_arr[i - 1].l_fork;
	}
	return (0);
}

int	spawn_threads(t_data *dat)
{
	int			i;

	i = 0;
	while (i < dat->n_philo)
	{
		init_philo_data(dat, &(dat->phi_arr[i]), i);
		i++;
	}
	dat->phi_arr[0].r_fork = dat->phi_arr[dat->n_philo - 1].l_fork;
	dat->start = get_time_ms();
	i = 0;
	while (i < dat->n_philo)
	{
		if (pthread_create(&(dat->phi_arr[i].thread),
				NULL, philo_thread, (void*) &(dat->phi_arr[i])))
		{
			return (1);
		}
		pthread_detach(dat->phi_arr[i].thread);
		i++;
	}
	check_death(dat);
	return (0);
}
