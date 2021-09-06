/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:58:44 by lorenuar          #+#    #+#             */
/*   Updated: 2021/09/03 11:45:53 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_available_fork(t_data *dat)
{
	int	i;

	i = 0;
	while (i < dat->n_philo && dat->forks)
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

int	give_fork(t_data *dat)
{
	int			i;
	t_sel_time	sel;

	sel = (t_sel_time){0, 0, -1};
	i = 0;
	while (i < dat->n_philo && dat->time_last_meal)
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

int	manage_threads(t_data *dat)
{
	give_fork(dat);
	while (1)
	{
		msleep(CPU_SAVER);
	}
	return (0);
}
