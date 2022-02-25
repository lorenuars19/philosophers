/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:49:27 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/25 13:19:51 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	philos should take N and N + 1 fork

	>>
		lock mutex and set state of
		lock(dat->mutex_forks[N]) + dat->forks[N] = FORK_HELD_BY_N
		AND
		lock(dat->mutex_forks[N + 1]) + dat->forks[N + 1] = FORK_HELD_BY_N

	*/
int	fork_take(t_data *dat, long philo_id)
{

	if (mutex_lock(&(dat->mutex_data)))
	{
		return (1);
	}
	if (mutex_lock(&(dat->mutex_fork[philo_id])))
	{
		return (1);
	}
	dat->forks[philo_id] = FORK_HELD_BY_N + philo_id;
	if (mutex_lock(&(dat->mutex_fork[philo_id + 1])))
	{
		return (1);
	}
	dat->forks[philo_id + 1] = FORK_HELD_BY_N + philo_id + 1;
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return (1);
	}

	return (0);
}
/*
	philos should release N and N + 1 fork

	>>
		unlock mutex and set state of
		lock(dat->mutex_forks[N]) + dat->forks[N] = FORK_HELD_BY_N
		AND
		lock(dat->mutex_forks[N + 1]) + dat->forks[N + 1] = FORK_HELD_BY_N

*/
int	fork_release(t_data *dat, long philo_id)
{
	if (mutex_lock(&(dat->mutex_data)))
	{
		return (1);
	}
	dat->meals_consumed[philo_id]++;
	if (mutex_unlock(&(dat->mutex_fork[philo_id])))
	{
		return (1);
	}
	dat->forks[philo_id] = FORK_AVAILABLE;
	if (mutex_unlock(&(dat->mutex_fork[philo_id + 1])))
	{
		return (1);
	}
	dat->forks[philo_id + 1] = FORK_AVAILABLE;
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return (1);
	}
	return(0);
}
