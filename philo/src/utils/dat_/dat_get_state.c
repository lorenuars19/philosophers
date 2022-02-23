/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dat_get_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:59:50 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/23 14:49:03 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dat_get_state(t_data *dat, long philo_id, t_phil_state *state)
{
	if (mutex_lock(dat->p_mu_data))
	{
		return (1);
	}
	if (philo_id >= 0 && philo_id < THREADS_MAX && state)
	{
		*state = dat->state[philo_id];
	}
	if (mutex_unlock(dat->p_mu_data))
	{
		return (1);
	}
	return (0);
}
