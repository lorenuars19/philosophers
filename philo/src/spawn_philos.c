/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:51:29 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/01 14:38:30 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define NODEBUG 1

void	*thread_philo(void *data)
{
	t_phil_dat	*pdat;
	t_data		*dat;

	pdat = ((t_phil_dat *)data);
	dat = pdat->data;

	pthread_mutex_lock(&(dat->mutex_data));

	while (pdat->wait_for_action)
	{
		if (dat->state[pdat->id] != STATE_DEAD)
		{
			return (0);
		}
	}
	pthread_mutex_unlock(&(dat->mutex_data));

	pthread_mutex_lock(&(dat->mutex_fork[0]));
	pthread_mutex_lock(&(dat->mutex_fork[1]));


	pthread_mutex_unlock(&(dat->mutex_fork[0]));
	pthread_mutex_unlock(&(dat->mutex_fork[1]));

	return ((void *)0);
}

#undef NODEBUG

int	spawn_philos(t_data *dat)
{
	t_phil_dat	philos[THREADS_MAX];
	int			i;

	i = 0;
	while (i < dat->n_philo)
	{
		philos[i] = (t_phil_dat){dat, i, 1};
		if (pthread_create(&(dat->threads[i]), NULL, thread_philo, (void *)&(philos[i])))
			return (1);
		if (time_get_now(&(dat->time_last_meal[i])))
			return (1);
		i++;
	}
	return (0);
}
