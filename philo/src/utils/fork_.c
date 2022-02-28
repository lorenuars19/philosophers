/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:49:27 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/28 11:28:31 by lorenuar         ###   ########.fr       */
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
	int	ret;

	ret = 0;
	if (mutex_lock(&(dat->mutex_data)))
	{
		ret = 1;
	}
	if (mutex_lock(&(dat->mutex_fork[philo_id])))
	{
		ret = 1;
	}
	dat->forks[philo_id] = FORK_HELD_BY_N + philo_id;
	if (mutex_unlock(&(dat->mutex_data)))
	{
		ret = 1;
	}
	if (dat_set_state(dat, philo_id, STATE_TOOK_L_FORK))
	{
		ret = 1;
	}
	if (mutex_lock(&(dat->mutex_data)))
	{
		ret = 1;
	}
	if (mutex_lock(&(dat->mutex_fork[philo_id + 1])))
	{
		ret = 1;
	}
	dat->forks[philo_id + 1] = FORK_HELD_BY_N + philo_id + 1;
	if (mutex_unlock(&(dat->mutex_data)))
	{
		ret = 1;
	}
	if (dat_set_state(dat, philo_id, STATE_TOOK_R_FORK))
	{
		ret = 1;
	}
	return (ret);
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
	int	ret;

	ret = 0;
	if (mutex_lock(&(dat->mutex_data)))
	{
		ret = 1;
	}
	dat->meals_consumed[philo_id]++;
	if (mutex_unlock(&(dat->mutex_fork[philo_id])))
	{
		ret = 1;
	}
	dat->forks[philo_id] = FORK_AVAILABLE;
	if (mutex_unlock(&(dat->mutex_fork[philo_id + 1])))
	{
		ret = 1;
	}
	dat->forks[philo_id + 1] = FORK_AVAILABLE;
	if (mutex_unlock(&(dat->mutex_data)))
	{
		ret = 1;
	}
	return(ret);
}
