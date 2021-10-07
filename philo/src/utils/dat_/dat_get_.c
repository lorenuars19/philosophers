/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dat_get_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:59:50 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 17:38:33 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dat_get_state(t_data *dat, long philo_id, t_phil_state *state)
{
	TML(philo_id); if (mutex_lock(&(dat->mutex_data), &(dat->check_data)))
	{
BM(MUTEX_DEADLOCKED)
		return (1);
	}
	if (philo_id >= 0 && philo_id < THREADS_MAX && state)
	{
		*state = dat->state[philo_id];
	}
	TMU(philo_id); if (mutex_unlock(&(dat->mutex_data), &(dat->check_data)))
	{
		return (1);
	}
	return (0);
}
