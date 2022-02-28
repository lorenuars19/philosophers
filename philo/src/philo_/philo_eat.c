/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:29:33 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/28 18:09:28 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_thread.h"

int	philo_eat(t_phil_dat *pdat, t_data *dat)
{
	philo_death(pdat, dat);
	if (fork_take(dat, pdat->id))
	{
BM(fork_take)
		return (1);
	}
BM(fork_take)
	if (dat_set_state(dat, pdat->id, STATE_EATING))
	{
		return (1);
	}
	msleep(dat->time_eat);
	if (fork_release(dat, pdat->id))
	{
		return (1);
	}
BM(fork_release)
	return (0);
}
