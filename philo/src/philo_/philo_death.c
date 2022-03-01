/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:19:49 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/01 14:53:04 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_death(t_phil_dat *pdat, t_data *dat)
{
	t_phil_state	state;

	dat_get_state(dat, pdat->id, &state);
	if (state == STATE_DEAD)
	{
		pthread_exit(NULL);
	}
}
