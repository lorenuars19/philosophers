/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:19:49 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/28 17:37:51 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_death(t_phil_dat *pdat, t_data *dat)
{
	t_phil_state	state;

	if (dat_get_state(dat, pdat->id, &state))
	{
		return ;
	}
	if (state == STATE_DEAD)
	{
		dat_set_state(dat, pdat->id, STATE_DEAD);
		pthread_exit(NULL);
	}
}
