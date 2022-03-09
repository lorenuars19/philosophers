/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:08:43 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/09 10:47:17 by lorenuar         ###   ########.fr       */
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
		if (get_time_ms() >= (dat->phi_arr[i].last_meal + dat->time_die))
		{
			if (dat->phi_arr[i].last_meal != 0)
			{
				return (&(dat->phi_arr[i]));
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
		return (&(dat->phi_arr[i]));
	}
	return (NULL);
}

void	check_threads(t_data *dat)
{
	int			is_death;
	t_phil_dat	*pda_philo_death;

	while (1)
	{
		is_death = 1;
		pda_philo_death = exec_mutex_safe(dat, dat, check_death);
		if (pda_philo_death)
			break ;
		is_death = 0;
		pda_philo_death = exec_mutex_safe(dat, dat, check_meals);
		if (pda_philo_death)
			break ;
	}
	if (pda_philo_death)
	{
		pda_philo_death->mutex = &(dat->mutex);
		pda_philo_death->start = dat->start;
		if (is_death == 1)
			print_timed_msg(pda_philo_death, "is dead");
		else if (is_death == 0)
			print_timed_msg(pda_philo_death, "has eaten enough");
		philo_dead_set(pda_philo_death, 1);
	}
	pthread_mutex_lock(&(dat->mutex));
}
