/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:19:49 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/09 11:16:48 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*set_last_meal(void *data)
{
	t_phil_dat	*pda;

	pda = (t_phil_dat *)data;
	pda->last_meal = get_time_ms();
	return (NULL);
}

void	*increment_meal(void *data)
{
	t_phil_dat	*pda;

	pda = (t_phil_dat *)data;
	pda->meals++;
	return (NULL);
}

static void	sub_philo_eat(t_phil_dat *pda)
{
	pthread_mutex_lock(pda->r_fork);
	print_timed_msg(pda, "has taken a fork");
	pthread_mutex_lock(pda->l_fork);
	print_timed_msg(pda, "has taken a fork");
	exec_mutex_safe(pda->data, (void *)pda, set_last_meal);
	print_timed_msg(pda, "is eating");
}

void	*philo_thread(void *data)
{
	t_phil_dat	*pda;

	pda = (t_phil_dat *)data;
	if (pda->id % 2 != 0)
		msleep(pda->time_eat * 0.6);
	exec_mutex_safe(pda->data, (void *)pda, set_last_meal);
	philo_dead_set(pda, 0);
	while (!philo_dead_get(pda))
	{
		sub_philo_eat(pda);
		msleep(pda->time_eat);
		pthread_mutex_unlock(pda->r_fork);
		pthread_mutex_unlock(pda->l_fork);
		exec_mutex_safe(pda->data, (void *)pda, increment_meal);
		print_timed_msg(pda, "is sleeping");
		msleep(pda->time_sleep);
		if (pda->max_meals > 0 && pda->meals >= pda->max_meals)
			return (NULL);
		print_timed_msg(pda, "is thinking");
	}
	return (NULL);
}
