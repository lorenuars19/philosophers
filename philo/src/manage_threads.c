/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:58:44 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/22 15:54:48 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	manage_threads(t_data *dat)
{
	int	i;
	int	check_death;

	i = 0;
	check_death = 0;
	while (check_death == 0)
	{
		check_death = check_philo_death(dat);
		if (check_death < 0)
		{
			//TODO HANDLE ERROR
		}
		else if (check_death == 1)
		{
			break ;
		}
		if (let_philos_eat(dat))
		{
			//TODO HANDLE ERROR
		}
		// msleep(CPU_SAVER);
		i++;
	}
	PDAT(manage_threads, dat);
	if (check_death > 0)
	{
		if (print_timed_msg(dat, check_death - 1, "died"))
		{
			return (1);
		}
	}
	PDAT(manage_threads END, dat);
	return (0);
}
