/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:29:33 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 15:33:26 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_wait_for_action(t_phil_dat *pdat, t_data *dat)
{
	t_phil_state	state;

	if (dat_get_state(dat, pdat->id, &(state)))
	{
		return (1);
	}
	while (state == STATE_THINKING)
	{
		if (dat_get_state(dat, pdat->id, &(state)))
		{
			return (1);
		}
		msleep(CPU_SAVER);
	}
	return (0);
}

int	philo_think(t_phil_dat *pdat, t_data *dat)
{

	if (dat_set_state(dat, pdat->id, STATE_THINKING))
	{
		return (1);
	}
	if (print_timed_msg(dat, pdat->id, "is thinking"))
	{
		return (1);
	}
	if (philo_wait_for_action(pdat, dat))
	{
		return (1);
	}
	return (0);
}
