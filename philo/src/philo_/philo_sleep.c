/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:29:33 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/28 17:58:45 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_thread.h"

int	philo_sleep(t_phil_dat *pdat, t_data *dat)
{
	philo_death(pdat, dat);
	if (dat_set_state(dat, pdat->id, STATE_SLEEPING))
	{
		return (1);
	}
	msleep(dat->time_sleep);
	return (0);
}
