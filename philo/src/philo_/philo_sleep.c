/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:29:33 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 15:32:28 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleep(t_phil_dat *pdat, t_data *dat)
{
	if (dat_set_state(dat, pdat->id, STATE_SLEEPING))
	{
		return (1);
	}
	if (print_timed_msg(dat, pdat->id, "is sleeping"))
	{
		return (1);
	}
	msleep(dat->time_sleep);
	return (0);
}
