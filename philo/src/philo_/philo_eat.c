/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:29:33 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/28 11:31:04 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_thread.h"

int	philo_eat(t_phil_dat *pdat, t_data *dat)
{
	if (dat_set_state(dat, pdat->id, STATE_EATING))
	{
		return (1);
	}
	if (fork_take(dat, pdat->id))
	{
		return (1);
	}
	msleep(dat->time_eat);
BM(philo_eat FORK RELEASE)
	if (fork_release(dat, pdat->id))
	{
		return (1);
	}
	return (0);
}
