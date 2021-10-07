/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:11:05 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 15:04:24 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_threads(t_data *dat)
{
	int	i;

	i = 0;
	while (i < dat->n_philo)
	{
		if (dat->threads[i] && pthread_join(dat->threads[i], NULL))
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

int	join_and_destroy(t_data *dat)
{
	if (join_threads(dat))
	{
		return (1);
	}
	if (destroy_mutexes(dat))
	{
		return (1);
	}
	return (0);
}
