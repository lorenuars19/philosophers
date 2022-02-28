/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:51:29 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/28 17:57:50 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_phil_dat(t_phil_dat phil_dat[THREADS_MAX])
{
	int	i;

	i = 0;
	while (i < THREADS_MAX)
	{
		phil_dat[i] = (t_phil_dat){NULL, -1};
		i++;
	}
}

int	spawn_philos(t_data *dat)
{
	t_phil_dat	phil_dat[THREADS_MAX];
	int			i;

	init_phil_dat(phil_dat);
	i = 0;
	while (i < dat->n_philo)
	{
		phil_dat[i] = (t_phil_dat){dat, i};
		if (pthread_create(&(dat->threads[i]), NULL,
				philo_thread, (void *)&(phil_dat[i])))
		{
			return (1);
		}
		if (time_get_now(&(dat->time_last_meal[i])))
		{
			return (1);
		}
		usleep(10000);
		i++;
	}
	return (0);
}
