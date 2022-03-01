/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:19:49 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/01 14:35:30 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_death(t_phil_dat *pdat, t_data *dat)
{
	t_phil_state	state;
	int				check_death;

	mutex_lock(&(dat->mutex_data));
	check_death = time_check_death(dat, dat->time_last_meal[pdat->id]);
	state = dat->state[pdat->id];
	if (check_death || state == STATE_DEAD)
	{
		dat->state[pdat->id] = STATE_DEAD;
		mutex_unlock(&(dat->mutex_data));
		pthread_exit(NULL);
	}
	mutex_unlock(&(dat->mutex_data));
}
