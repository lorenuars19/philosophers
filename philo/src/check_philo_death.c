/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:42:51 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 15:07:34 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	time_check_death(t_data *dat, t_time philo_time, long philo_id)
{
	t_time	now;

	if (time_get_now(&now))
	{
		return (1);
	}
	if ((now >= (philo_time + dat->time_die)))
	{
		if (dat_set_state(dat, philo_id, STATE_DEAD))
		{
			return (1);
		}
	}
	return (0);
}

int	check_philo_death(t_data *dat)
{
	int	x;

	x = 0;
	if (mutex_lock(&(dat->mutex_data), &(dat->check_data)))
	{
		return (1);
	}
	while (x < dat->n_philo)
	{
		if (time_check_death(dat, dat->time_last_meal[x], x)))
		{
			break;
		}
		if (dat->state[x] == STATE_DEAD)
		{
			if (dat->philo_death == NOBODY_DEAD)
			{
				dat->philo_death = x;
			}
		}
		x++;
	}
	if (mutex_unlock(&(dat->mutex_data), &(dat->check_data)))
	{
		return (1);
	}
	return (0);
}
