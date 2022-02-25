/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_philos_eat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:44:48 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/25 13:36:41 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



static int select_philo(t_data *dat)
{
	t_sel_time sel;
	int i;

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
	return (sel.sel_ind);
}

int	check_philo_can_eat(t_data *dat, int id)
{
	int	can_eat;

	can_eat = 0;

	if (dat->forks[id] == FORK_AVAILABLE
		&& dat->forks[id + 1] == FORK_AVAILABLE)
	{
		can_eat = 1;
	}
	return (can_eat);
}

int	let_philos_eat(t_data *dat)
{
	int	id;
	int	can_eat;
	int	ret;

	ret = 0;
	if (mutex_lock(&(dat->mutex_data)))
	{
		return (1);
	}
	id = select_philo(dat);
	can_eat = check_philo_can_eat(dat, id);
	if (can_eat < 0)
	{
		ret = 1;
	}
	dat->state[id] = STATE_READY_EATING;
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return (1);
	}
	return (ret);
}
