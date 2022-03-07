/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:08:43 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/07 14:56:41 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_data *dat)
{
	int		dead;
	int		i;

	dead = 0;
	while (!dead)
	{
		i = 0;
		while (i < dat->n_philo)
		{
			if (dat->phi_arr[i].last_meal != 0 && (get_time_ms()
					>= (dat->phi_arr[i].last_meal + dat->time_die)))
			{
				dead = 1;
			}
			if (dead)
			{
				if (dat->max_meals == 0)
				{
					print_timed_msg(&(dat->phi_arr[i]), "is dead");
					pthread_mutex_lock(&(dat->mutex_print));
				}
			}
			i++;
		}
	}
}
