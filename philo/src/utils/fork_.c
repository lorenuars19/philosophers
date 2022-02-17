/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:49:27 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/07 13:35:55 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dbg_print_fork(t_data *dat, long philo_id)
{
	printf(">> FORK >> PHI ID %ld | STATE %s\n",
		philo_id,
		states[dat->state[philo_id]]);
}

static int	select_fork(t_data *dat)
{
	t_sel	sel;
	int		i;

	i = 0;
	sel = (t_sel){0, 0, -1};
	while (i < dat->n_philo)
	{
		sel.tmp = dat->forks[i];
		if (sel.tmp == FORK_AVAILABLE)
		{
			sel.sel = sel.tmp;
			sel.sel_ind = i;
		}
		i++;
	}
	if (sel.sel_ind == -1)
	{
		return (-1);
	}
	return (sel.sel_ind);
}

int	fork_take(t_data *dat, long philo_id)
{
	int	fork_id;

	fork_id = select_fork(dat);
	if (fork_id < 0)
	{
		return (1);
	}
	dat->forks[philo_id] = FORK_HELD_BY_N + philo_id;

dbg_print_fork(dat, philo_id);

	return (0);
}

int	fork_release(t_data *dat, long philo_id)
{
dbg_print_fork(dat, philo_id);
	return (0);
}
