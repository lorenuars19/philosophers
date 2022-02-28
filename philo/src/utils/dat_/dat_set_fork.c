/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dat_set_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:01:19 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/28 18:25:00 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dat_set_fork(t_data *dat, long philo_id, t_fork fork)
{
	int	ret;

	ret = 0;
	if (mutex_lock(&(dat->mutex_data)))
	{
		return (1);
	}
	if (philo_id >= 0 && philo_id < THREADS_MAX)
	{
		dat->forks[philo_id] = fork;
	}
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return (1);
	}
	return (ret);
}
