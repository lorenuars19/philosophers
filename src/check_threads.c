/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:08:43 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/08 14:35:45 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(void *data)
{
	int		i;
	t_data	*dat;

	dat = (t_data *)data;
	i = 0;
	while (i < dat->n_philo)
	{
		if (dat->phi_arr[i].last_meal != 0 && (get_time_ms()
				>= (dat->phi_arr[i].last_meal + dat->time_die)))
		{
			if (dat->max_meals == 0)
			{
				print_timed_msg(&(dat->phi_arr[i]), "is dead");
				return ((void *)1);
			}
		}
		i++;
	}
	return (NULL);
}

void	*check_meals(void *data)
{
	t_data	*dat;
	int		everyone_has_eaten;
	int		i;

	i = 0;
	dat = (t_data *)data;
	everyone_has_eaten = dat->n_philo;
	while (i < dat->n_philo && dat->max_meals > 0)
	{
		if (dat->phi_arr[i].meals >= dat->max_meals)
		{
			everyone_has_eaten--;
		}
		i++;
	}
	if (everyone_has_eaten == 0)
	{
		return ((void *)1);
	}
	return (NULL);
}

void	check_threads(t_data *dat)
{
	while (1)
	{
		if (exec_mutex_safe(dat, dat, check_death))
		{
			pthread_mutex_lock(&(dat->mutex));
			return ;
		}
		if (exec_mutex_safe(dat, dat, check_meals))
		{
			pthread_mutex_lock(&(dat->mutex));
			return ;
		}
	}
	return ;
}
