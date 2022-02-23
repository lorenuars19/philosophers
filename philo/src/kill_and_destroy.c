/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:11:05 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/23 15:10:39 by lorenuar         ###   ########.fr       */
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
		if (pthread_mutex_destroy(&(dat->mu_fork[i])))
		{
			return (1);
		}
		i++;
	}
	msleep(100);
	dat->p_mu_data = NULL;
	if (pthread_mutex_destroy(&(dat->mu_data)))
	{
		return (1);
	}
	dat->p_mu_data = NULL;
	dat->p_mu_print = NULL;
	if (pthread_mutex_destroy(&(dat->mu_print)))
	{
		return (1);
	}
	dat->p_mu_print = NULL;
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
