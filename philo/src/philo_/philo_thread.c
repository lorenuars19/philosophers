/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:19:49 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/07 13:19:30 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sub_philo_eat(t_phil_dat *pda)
{
	if (pthread_mutex_lock(pda->r_fork))
	{
		return (1);
	}
	print_timed_msg(pda, "has taken R fork");
	if (pthread_mutex_lock(pda->l_fork))
	{
		return (1);
	}
	print_timed_msg(pda, "has taken L fork");
	pda->last_meal = get_time_ms();
	print_timed_msg(pda, "is eating");
	msleep(pda->time_eat);
	if (pthread_mutex_unlock(pda->r_fork))
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
	if (pda->id == 1)
		msleep(pda->time_eat * 0.9);
	pda->last_meal = get_time_ms();
	while ((pda->last_meal != 0 && (get_time_ms() <=
			(pda->last_meal + pda->time_die) &&
			(pda->max_meals == 0 || pda->meals < pda->max_meals))))
	{
		if (sub_philo_eat(pda))
		{
			return (NULL);
		}
		print_timed_msg(pda, "is sleeping");
		msleep(pda->time_sleep);
		print_timed_msg(pda, "is thinking");
	}
	pthread_mutex_lock(pda->mutex_print);
	pthread_mutex_lock(pda->mutex_print);
	print_timed_msg(pda, "is dead");
	return (NULL);
}
