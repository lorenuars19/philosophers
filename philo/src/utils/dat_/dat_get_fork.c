/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dat_get_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:59:50 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/07 13:08:40 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dat_get_fork(t_data *dat, long philo_id, t_fork *fork)
{
	if (mutex_lock(&(dat->mutex_data)))
	{
		return (1);
	}
	if (philo_id >= 0 && philo_id < THREADS_MAX && fork)
	{
		*fork = dat->forks[philo_id];
	}
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return (1);
	}
	return (0);
}
