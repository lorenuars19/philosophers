/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_philos_eat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:44:48 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/25 13:07:06 by lorenuar         ###   ########.fr       */
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
	return (sel.sel_ind);
}

int	check_philo_can_eat(t_data *dat, int id)
{
	int	can_eat;

	can_eat = 0;
	if (mutex_lock(&(dat->mutex_data)))
	{
		return (1);
	}
	if (dat->forks[id] == FORK_AVAILABLE
		&& dat->forks[id + 1] == FORK_AVAILABLE)
	{
		can_eat = 1;
	}
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return (1);
	}
	return (can_eat);
}

int	make_philo_eat(t_data *dat, int id)
{
	if (mutex_lock(&(dat->mutex_data)))
	{
		return (1);
	}
	dat->state[id] = STATE_READY_EATING;
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return (1);
	}
}

int	let_philos_eat(t_data *dat)
{
	int	id;
	int	can_eat;
	// Select philo that is nearest to its death
	id = select_philo(dat);

	can_eat = check_philo_can_eat(dat, id);
	if (can_eat < 0)
	{
		return (1);
	}
	if (can_eat == 1 && make_philo_eat(dat, id))
	{
		return (1);
	}
	return (0);
}
