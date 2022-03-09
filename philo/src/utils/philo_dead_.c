/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:04:50 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/08 18:40:45 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead_set(t_phil_dat *pda, int val)
{
	if (pda->mutex)
	{
		pthread_mutex_lock(pda->mutex);
		pda->is_dead = val;
		pthread_mutex_unlock(pda->mutex);
	}
}

int	philo_dead_get(t_phil_dat *pda)
{
	int	is_dead;

	is_dead = 0;
	if (pda->mutex)
	{
		pthread_mutex_lock(pda->mutex);
		is_dead = pda->is_dead;
		pthread_mutex_unlock(pda->mutex);
	}
	return (is_dead);
}
