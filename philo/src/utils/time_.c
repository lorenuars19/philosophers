/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:28:18 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 12:11:13 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_get_now(t_time *ptr_time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		return (1);
	}
	if (ptr_time)
		*ptr_time = (tv.tv_sec) * 1000LL + (tv.tv_usec) / 1000;
	return (0);
}

int	time_check_death(t_data *dat, t_time philo_time, t_phil_state *state)
{
	t_time	now;

	if (time_get_now(&now))
	{
		return (1);
	}
	if ((now >= (philo_time + dat->time_die)) && state)
	{
		*state = STATE_DEAD;
	}
	return (0);
}
