/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:19:49 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/06 12:10:44 by lorenuar         ###   ########.fr       */
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

void	*philo_thread(void *data)
{
	t_phil_dat	*pdat;
	t_data		*dat;

	pdat = ((t_phil_dat *)data);
	dat = pdat->data;

	if (wait_for_action(pdat, dat))
	{
		return (NULL);
	}



	if (dat_set_thread(dat, pdat->id, (pthread_t)0)) // END, protect joins from dead threads
	{
		return (NULL);
	}
	return (NULL);
}
