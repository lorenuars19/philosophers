/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:42:51 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/01 14:52:52 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sub_philo_death(t_data *dat, int x)
{
	int	i;

	if (mutex_unlock(&(dat->mutex_data)))
	{
		return (-1);
	}
	if (dat_set_state(dat, x, STATE_DEAD))
	{
		return (-1);
	}
	if (mutex_lock(&(dat->mutex_data)))
	{
		return (-1);
	}
	i = 0;
	while (i < THREADS_MAX)
	{
		dat->state[i] = STATE_DEAD;
		i++;
	}
	return (0);
}

int	check_philo_death(t_data *dat)
{
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
			if (sub_philo_death(dat, x))
			{
				return (-1);
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
