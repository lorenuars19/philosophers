/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_philos_eat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:44:48 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 14:52:36 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_max_meals_reached(t_data *dat)
{
	//TODO check if every philosoher has eaten at least `dat->max_meals` times
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
	printf("give_fork : sel_time : %llu | ind : %ld\n", sel.sel, sel.sel_ind);
	return (0);
}


int	let_philos_eat(t_data *dat)
{
	// Select philo that is nearest to its death



	return (0);
}
