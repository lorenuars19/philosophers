/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:29:33 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/28 17:36:17 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_thread.h"

int	philo_sleep(t_phil_dat *pdat, t_data *dat)
{
	t_phil_state	state;

	philo_death(pdat, dat);
	if (dat_get_state(dat, pdat->id, &state))
	{
		return (1);
	}
	if (state == STATE_DEAD || state != STATE_TOOK_R_FORK)
	{
		return (1);
	}
	if (dat_set_state(dat, pdat->id, STATE_SLEEPING))
	{
		return (1);
	}
	msleep(dat->time_sleep);
	return (0);
}
