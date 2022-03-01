/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:58:44 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/01 13:36:56 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_max_meals_reached(t_data *dat)
{
	int	i;
	int	philo_id;
	int	check;
	int	ret;

	philo_id = 0;
	check = 0;
	ret = 0;
	if (mutex_lock(&(dat->mutex_data)))
	{
		return (1);
	}
	while (philo_id < dat->n_philo)
	{
		if (dat->meals_consumed[philo_id] >= dat->max_meals)
		{
			check++;
		}
		philo_id++;
	}
	if (check == dat->n_philo)
	{
		i = 0;
		while (i < THREADS_MAX)
		{
			dat->state[i] = STATE_DEAD;
			i++;
		}
		ret = 1;
	}
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return (1);
	}
	return (ret);
}

int	manage_threads(t_data *dat, long max_meals)
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
			break;
		}
		if ((max_meals > 0 && check_max_meals_reached(dat)))
		{
			break ;
		}
		i++;
	}
	return (0);
}
