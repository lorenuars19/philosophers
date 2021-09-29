/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:51:29 by lorenuar          #+#    #+#             */
/*   Updated: 2021/09/29 09:05:14 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_philo(void *data)
{
	int			wait_for_action;
	t_phil_dat	*pdat;
	t_data		*dat;

	pdat = ((t_phil_dat *)data);
	dat = pdat->data;

	wait_for_action = 1;
	while (wait_for_action)
	{
		pthread_mutex_lock(&(dat->mutex_data));
		dat->state[pdat->id] = STATE_THINKING;
		// printf("ID %02d STATE %04d\n", pdat->id, dat->state[pdat->id]);
		if (dat->state[pdat->id] != STATE_THINKING)
		{
			printf("\n=============\n");
			wait_for_action = 0;
		}
		pthread_mutex_unlock(&(dat->mutex_data));
		msleep(CPU_SAVER * 100);
	}
	pthread_mutex_unlock(&(dat->mutex_data));

	pthread_mutex_lock(&(dat->mutex_print));
	printf("Received Action || ID %d STATE = %d\n", pdat->id, dat->state[pdat->id]);
	pthread_mutex_unlock(&(dat->mutex_print));


	pthread_mutex_lock(&(dat->mutex_fork[0]));
	pthread_mutex_lock(&(dat->mutex_fork[1]));


	pthread_mutex_unlock(&(dat->mutex_fork[0]));
	pthread_mutex_unlock(&(dat->mutex_fork[1]));



	return ((void *)0);
}

int	spawn_philos(t_data *dat)
{
	t_phil_dat	philos[THREADS_MAX];
	int			i;

	i = 0;
	while (i < dat->n_philo)
	{
		philos[i] = (t_phil_dat){dat, i};
		if (pthread_create(&(dat->threads[i]), NULL, thread_philo,
				(void *)(&(philos[i]))))
			return (1);
		if (time_get_now(&(dat->time_last_meal[i])))
			return (1);
		i++;
	}
	return (0);
}
