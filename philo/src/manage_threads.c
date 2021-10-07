/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:58:44 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 14:44:37 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int select_philo(t_data *dat)
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
	printf("give_fork : sel_time : %llu | ind : %ld\n", sel.sel, sel.sel_ind);
	if (check_available_fork(dat))
		return (1);
	return (0);
}



int	check_max_meals_reached(t_data *dat)
{
	//TODO check if every philosoher has eaten at least `dat->max_meals` times
	return (0);
}

int manage_threads(t_data *dat)
{
	int i;

	dat->philo_death = NOBODY_DEAD;
	i = 0;
	while (dat->philo_death == NOBODY_DEAD)
	{
		if (check_philo_death(dat))
		{
			return (1);
		}
		if (dat->philo_death != NOBODY_DEAD)
		{
			break;
		}

		if (let_philos_eat(dat))
		{
			return (1);
		}

		if (check_max_meals_reached(dat))
		{
			return (1);
		}
		msleep(CPU_SAVER);
		i++;
	}

	PDAT(manage_threads, dat);
	if (dat->philo_death != NOBODY_DEAD)
	{
		if (print_timed_msg(dat, dat->philo_death, "died"))
		{
			return (1);
		}
	}
	PDAT(manage_threads END, dat);
	return (0);
}
