/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:19:49 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 14:55:04 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	wait_for_action(t_phil_dat *pdat, t_data *dat)
{
	t_phil_state	state;

	while (pdat->wait_for_action)
	{
		if (dat_get_state(dat, pdat->id, &(state)))
		{
			return (1);
		}
		if (state != STATE_DEAD)
		{
			return (0);
		}
	}
	return (0);
}

static	int	philo_think(t_phil_dat *pdat, t_data *dat)
{
	if (dat_set_state(dat, pdat->id, STATE_THINKING))
	{
		return (1);
	}
	if (print_timed_msg(dat, pdat->id, "is thinking"))
	{
		return (1);
	}
	return (0);
}

static	int	philo_sleep(t_phil_dat *pdat, t_data *dat)
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

static	int	philo_eat(t_phil_dat *pdat, t_data *dat)
{
	if (print_timed_msg(dat, pdat->id, "is eating"))
	{
		return (1);
	}
	return (0);
}

void	*philo_thread(void *data)
{
	t_phil_dat	*pdat;
	t_data		*dat;

	pdat = ((t_phil_dat *)data);
	dat = pdat->data;

	if (philo_thinking(pdat, dat))
	{
		return (NULL);
	}

	if (wait_for_action(pdat, dat))
	{
		return (NULL);
	}




	return (NULL);
}
