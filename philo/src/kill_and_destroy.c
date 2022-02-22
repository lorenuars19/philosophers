/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:11:05 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/22 17:26:00 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	kill_threads(t_data *dat)
{
	int	i;

	i = 0;
	usleep(((dat->time_sleep) * 1.1) * 1000);
	while (i < dat->n_philo)
	{
		if (dat->threads[i] && pthread_detach(dat->threads[i]))
		{
			return (1);
		}
		dat->threads[i] = (pthread_t) NULL;
		i++;
	}
	return (0);
}

static int	destroy_mutexes(t_data *dat)
{
	int	i;

	i = 0;
	while (i < dat->n_philo)
	{
		if (pthread_mutex_destroy(&(dat->mutex_fork[i])))
		{
			return (1);
		}
		i++;
	}
	if (pthread_mutex_destroy(&(dat->mutex_data)))
	{
		return (1);
	}
	if (pthread_mutex_destroy(&(dat->mutex_print)))
	{
		return (1);
	}
	return (0);
}

int	kill_and_destroy(t_data *dat)
{

PDAT(kill_and_destroy, dat)

	if (kill_threads(dat))
	{
		return (1);
	}
	if (destroy_mutexes(dat))
	{
		return (1);
	}
	return (0);
}
