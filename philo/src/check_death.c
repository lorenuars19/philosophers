/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:08:43 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/07 09:42:11 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_data *dat)
{
	int		i;
	int		dead;

	dead = 0;
	while (!dead)
	{
		i = 0;
		while (i < dat->n_philo)
		{
			dead = time_check_death(dat, dat->phi_arr[i].last_meal);
			if (dead)
			{
				if (dat->max_meals == 0)
				{
					print_timed_msg(&(dat->phi_arr[i]), "is dead");
				}
				return ;
			}
		}
	}
	return ;
}
