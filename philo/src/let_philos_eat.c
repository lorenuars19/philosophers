/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_philos_eat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:44:48 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/22 12:35:52 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_max_meals_reached(t_data *dat)
{
	int	philo_id;
	int	check;

	philo_id = 0;
	check = 0;
	while (philo_id < dat->n_philo)
	{
		if (dat->meals_consumed[philo_id] == dat->max_meals)
		{
			check++;
		}
	}
	if (check == dat->n_philo)
	{
		return (1);
	}
	return (0);
}

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
// printf(">=> give_fork : sel_time : %llu | ind : %ld\n", sel.sel, sel.sel_ind);
	return (sel.sel_ind);
}

int	let_philos_eat(t_data *dat)
{
	int	id;
	// Select philo that is nearest to its death
	id = select_philo(dat);

	// TODO request L FORK
	if (dat_set_state(dat, id, STATE_REQUEST_L_FORK))
	{
		return (1);
	}
	if (fork_take(dat, id))
	{
		return (1);
	}
	if (dat_set_state(dat, id, STATE_TOOK_L_FORK))
	{
		return (1);
	}

	// TODO request R FORK
	if (dat_set_state(dat, id, STATE_REQUEST_R_FORK))
	{
		return (1);
	}
	if (fork_take(dat, id))
	{
		return (1);
	}
	if (dat_set_state(dat, id, STATE_TOOK_R_FORK))
	{
		return (1);
	}
	// TODO When BOTH forks are acquired, let philo eat

	if (dat_set_state(dat, id, STATE_READY_EATING))
	{
		return (1);
	}
	return (0);
}
