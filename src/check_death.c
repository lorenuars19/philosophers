/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 09:08:43 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/08 13:55:27 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	sub_check_death(t_data *dat)
{
	int	i;

	i = 0;
	while (i < dat->n_philo)
	{
		if (dat->phi_arr[i].last_meal != 0 && (get_time_ms()
				>= (dat->phi_arr[i].last_meal + dat->time_die)))
		{
			if (dat->max_meals == 0)
			{
				print_timed_msg(&(dat->phi_arr[i]), "is dead");
				pthread_mutex_lock(&(dat->mutex));
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static int	sub_check_meals(t_data *dat)
{
	int	everyone_has_eaten;
	int	i;

	i = 0;
	everyone_has_eaten = dat->n_philo;
	while (i < dat->n_philo)
	{
		if (dat->phi_arr[i].meals >= dat->max_meals)
		{
			// print_timed_msg(&(dat->phi_arr[i]), " has eaten enough");
			everyone_has_eaten--;
		}
		i++;
	}
	if (everyone_has_eaten == 0)
	{
printf("sssss\n");
		return (1);
	}
	return (0);
}

void	check_death(t_data *dat)
{
	while (1)
	{
		mutex_lock(&(dat->mutex));
		if (sub_check_death(dat))
		{
			return ;
		}
		if (sub_check_meals(dat))
		{
			return ;
		}
		mutex_unlock(&(dat->mutex));
	}
}
