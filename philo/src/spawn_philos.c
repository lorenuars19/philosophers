/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:51:29 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/06 11:21:56 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	spawn_philos(t_data *dat)
{
	t_phil_dat	phil_dat[THREADS_MAX];
	int			i;

	i = 0;
	while (i < dat->n_philo)
	{
		phil_dat[i] = (t_phil_dat){dat, i, 1};
		if (pthread_create(&(dat->threads[i]), NULL, thread_philo, (void *)&(phil_dat[i])))
			return (1);
		if (time_get_now(&(dat->time_last_meal[i])))
			return (1);
		i++;
	}
	return (0);
}
