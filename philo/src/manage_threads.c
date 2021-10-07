/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:58:44 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 14:49:36 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"







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
			break ;
		}
		if (let_philos_eat(dat))
		{
			break ;
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
