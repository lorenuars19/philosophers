/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:29:33 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/01 14:18:04 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_phil_dat *pdat, t_data *dat)
{
	t_time	now;

	philo_death(pdat, dat);
	if (fork_take(dat, pdat->id))
	{
		return (1);
	}
	if (dat_set_state(dat, pdat->id, STATE_EATING))
	{
		return (1);
	}
	if (time_get_now(&now))
	{
		return (1);
	}
	if (dat_set_time_last_meal(dat, pdat->id, now))
	{
		return (1);
	}
	msleep(dat->time_eat);
	if (fork_release(dat, pdat->id))
	{
		return (1);
	}
	return (0);
}
