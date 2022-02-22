/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:42:51 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/22 15:52:44 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	time_check_death(t_data *dat, t_time philo_time)
{
	t_time	now;

	if (time_get_now(&now))
	{
		//TODO handle error
	}
	if ((now >= (philo_time + dat->time_die)))
	{
		return (1);
	}
	return (0);
}

int	check_philo_death(t_data *dat)
{
	int i;
	int	x;
	int	check_death;
	int	ret;

	x = 0;
	ret = 0;
	if (mutex_lock(&(dat->mutex_data)))
	{
		return (-1);
	}
	while (x < dat->n_philo)
	{
		check_death = time_check_death(dat, dat->time_last_meal[x]);
		if (check_death < 0)
		{
			return (-1);
		}
		if (check_death == 1)
		{
			ret = x + 1;
			dat->state[x] = STATE_DEAD;
			i = 0;
			while (i < THREADS_MAX)
			{
				dat->state[i] = STATE_DEAD;
				i++;
			}
			break ;
		}
		x++;
	}
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return (-1);
	}
	return (ret);
}
