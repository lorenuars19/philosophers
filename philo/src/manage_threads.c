/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:58:44 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/01 15:05:38 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_available_fork(t_data *dat)
{
	int i;

	i = 0;
	while (i < dat->n_philo)
	{
		if (dat->forks[i] == FORK_DEADLOCKED)
		{
			BM(FORK_DEADLOCKED);
			DE(i);
			return (1);
		}
		if (dat->forks[i] == FORK_AVAILABLE)
			break;
		i++;
	}
	DM(AVAILABLE_FORK, i);

	return (0);
}

int select_philo(t_data *dat)
{
	int i;
	t_sel_time sel;

	sel = (t_sel_time){0, 0, -1};
	i = 0;
	while (i < dat->n_philo)
	{
		sel.tmp = dat->time_last_meal[i];
		if (sel.sel < sel.tmp)
		{
			sel.sel = sel.tmp;
			sel.sel_ind = i;
		}
		i++;
	}
	printf("give_fork : sel_time : %llu | ind : %ld\n", sel.sel, sel.sel_ind);
	if (check_available_fork(dat))
		return (1);
	return (0);
}

int check_philo_death(t_data *dat)
{
	t_time	now;
	int		x;

	x = 0;
	if (time_get_now(&now))
	{
		return (1);
	}
	while (x < dat->n_philo)
	{

WBM(check_philo_death)

		printf("x %d last_meal %lld die %lld death %lld now %lld\n",
			x, dat->time_last_meal[x], dat->time_die, (dat->time_last_meal[x] + dat->time_die), now);

		if (now >= (dat->time_last_meal[x] + dat->time_die))
		{
			dat->state[x] = STATE_DEAD;
			dat->everyone_alive = 1 + x;
		}
		x++;
	}
	return (0);
}

int manage_threads(t_data *dat)
{
	int	i;

	if (pthread_mutex_lock(&(dat->mutex_data)))
	{
		return (1);
	}

	dat->everyone_alive = NOBODY_DEAD;
	i = 0;
	while (dat->everyone_alive == NOBODY_DEAD)
	{

WBM(manage_threads)

		if (i == 250)
		{

			if (check_philo_death(dat))
			{
				return (1);
			}
			if (dat->everyone_alive != NOBODY_DEAD)
			{
				return (1);
			}

			dat->state[0] = STATE_EATING;

PDAT(manage_threads, dat);
			if (pthread_mutex_unlock(&(dat->mutex_data)))
			{
				return (1);
			}
		}
		msleep(CPU_SAVER);
		i++;
	}
	if (pthread_mutex_lock(&(dat->mutex_data)))
	{
		return (1);
	}
	if (dat->everyone_alive)
	{
		printf("Philo N %d died\n", dat->everyone_alive - 1);
	}
	if (pthread_mutex_unlock(&(dat->mutex_data)))
	{
		return (1);
	}
	return (0);
}
