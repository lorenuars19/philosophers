/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:19:49 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 17:59:45 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int sub_philo_thread(t_phil_dat *pdat, t_data *dat)
{
BM(sub_philo_thread);
	if (philo_think(pdat, dat))
	{
		return (1);
	}
	if (philo_eat(pdat, dat))
	{
		return (1);
	}
	if (philo_sleep(pdat, dat))
	{
		return (1);
	}
	return (0);
}

void *philo_thread(void *data)
{
	t_phil_state	state;
	t_phil_dat		*pdat;
	t_data			*dat;

	pdat = ((t_phil_dat *)data);
	dat = pdat->data;
	state = STATE_THINKING;
	while (state != STATE_DEAD)
	{
DE(state);
		if (sub_philo_thread(pdat, dat))
		{
			return (NULL);
		}
		if (state == STATE_DEAD)
		{
			break ;
		}
		if (dat_get_state(dat, pdat->id, &state))
		{
			return (NULL);
		}
	}

	return (NULL);
}
