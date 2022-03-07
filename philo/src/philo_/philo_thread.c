/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:19:49 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/07 10:04:06 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sub_philo_eat(t_phil_dat *pda)
{
	if (pthread_mutex_unlock(pda->r_fork))
	{
		return (1);
	}
	print_timed_msg(pda, "has taken R fork");
	if (mutex_lock(pda->l_fork))
	{
		return (1);
	}
	print_timed_msg(pda, "has taken L fork");
	time_get_now(&(pda->last_meal));
	print_timed_msg(pda, "is eating");
	msleep(pda->time_eat);
	if (mutex_unlock(pda->r_fork))
	{
		return (1);
	}
	if (pthread_mutex_unlock(pda->l_fork))
	{
		return (1);
	}
	pda->meals++;
	return (0);
}

void	*philo_thread(void *data)
{
	t_phil_dat	*pda;

	pda = (t_phil_dat *)data;
	msleep(pda->time_sleep + pda->time_eat * 1.2);
	if (pda->id % 2 != 0)
		msleep(pda->time_sleep + pda->time_eat * 1.2);
	time_get_now(&(pda->last_meal));
	while (pda->max_meals == 0 || pda->meals < pda->max_meals)
	{
		if (sub_philo_eat(pda))
		{
			return (NULL);
		}
		print_timed_msg(pda, "is sleeping");
		msleep(pda->time_sleep);
		print_timed_msg(pda, "is thinking");
	}
	return (NULL);
}
