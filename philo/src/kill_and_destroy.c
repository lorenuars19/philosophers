/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:11:05 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/08 13:54:49 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	destroy_mutexes(t_data *dat)
{
	int	i;

	i = 0;
	while (i < dat->n_philo)
	{
		if (pthread_mutex_destroy(dat->phi_arr[i].r_fork))
		{
			return (1);
		}
	}
	if (pthread_mutex_destroy(&(dat->mutex)))
	{
		return (1);
	}
	return (0);
}

int	kill_and_destroy(t_data *dat)
{
	if (destroy_mutexes(dat))
	{
		return (1);
	}
	free(dat->phi_arr);
	return (0);
}
