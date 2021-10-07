/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dat_set_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:01:19 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 15:02:45 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dat_set_thread(t_data *dat, long philo_id, pthread_t value)
{
	if (mutex_lock(&(dat->mutex_data), &(dat->check_data)))
	{
		return (1);
	}
	if (philo_id >= 0 && philo_id < THREADS_MAX)
	{
		dat->threads[philo_id] = value;
	}
	if (mutex_unlock(&(dat->mutex_data), &(dat->check_data)))
	{
		return (1);
	}
	return (0);
}

int	dat_set_state(t_data *dat, long philo_id, t_phil_state state)
{
	static char	*states[STATE_MAX] = {
		"is thinking", "is eating", "is sleeping", "is dead"};

	if (mutex_lock(&(dat->mutex_data), &(dat->check_data)))
	{
		return (1);
	}
	if (philo_id >= 0 && philo_id < THREADS_MAX)
	{
		dat->state[philo_id] = state;
		if (state >= 0 && state < STATE_MAX
			&& print_timed_msg(dat, philo_id, states[state]))
		{
			return (1);
		}
	}
	if (mutex_unlock(&(dat->mutex_data), &(dat->check_data)))
	{
		return (1);
	}
	return (0);
}
