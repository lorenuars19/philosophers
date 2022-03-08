/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:19:49 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/08 13:56:00 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_meal(t_phil_dat *pda)
{
	mutex_lock(pda->mut)
}

void	*philo_thread(void *data)
{
	t_phil_dat	*pda;

	pda = (t_phil_dat *)data;
	if (pda->id % 2 != 0)
		msleep(pda->time_eat * 0.6);
	pda->last_meal = get_time_ms();
	while ((pda->max_meals == 0 || pda->meals < pda->max_meals))
	{
		pthread_mutex_lock(pda->r_fork);
		print_timed_msg(pda, "has taken a fork");
		pthread_mutex_lock(pda->l_fork);
		print_timed_msg(pda, "has taken a fork");
		pda->last_meal = get_time_ms();
		print_timed_msg(pda, "is eating");
		msleep(pda->time_eat);
		pthread_mutex_unlock(pda->r_fork);
		pthread_mutex_unlock(pda->l_fork);
		pda->meals++;
		print_timed_msg(pda, "is sleeping");
		msleep(pda->time_sleep);
		print_timed_msg(pda, "is thinking");
	}
	pda->last_meal = 1;
	print_timed_msg(pda, "has eaten enough");
	msleep(pda->time_die);
	return (NULL);
}
