/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dat_get_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:59:50 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 17:15:24 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dat_get_state(t_data *dat, long philo_id, t_phil_state *state)
{
printf("\ndat_get_state CHECK_DATA %d\n",dat->check_data);
	TML(philo_id); if (mutex_lock(&(dat->mutex_data), &(dat->check_data)))
	{
		return (1);
	}
	if (philo_id >= 0 && philo_id < THREADS_MAX && state)
	{
		*state = dat->state[philo_id];
	}
BM(ABOUT TO UNLOCK MUTEX);
	TMU(philo_id); if (mutex_unlock(&(dat->mutex_data), &(dat->check_data)))
	{
		return (1);
	}
	return (0);
}
