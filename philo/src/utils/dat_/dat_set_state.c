/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dat_set_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:01:19 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/01 14:15:26 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dat_set_state(t_data *dat, long philo_id, t_phil_state state)
{
	int	ret;

	ret = 0;
	if (mutex_lock(&(dat->mutex_data)))
	{
		return (1);
	}
	if (dat->state[philo_id] == STATE_DEAD)
	{
		ret = 1;
	}
	if (philo_id >= 0 && philo_id < THREADS_MAX
		&& dat->state[philo_id] != STATE_DEAD)
	{
		dat->state[philo_id] = state;
		if (state >= 0 && state < STATE_MAX
			&& print_timed_msg(dat, philo_id, state))
		{
			ret = 1;
		}
	}
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return (1);
	}
	return (ret);
}
