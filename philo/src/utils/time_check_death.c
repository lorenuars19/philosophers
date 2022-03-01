/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_check_death.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:28:18 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/01 13:59:43 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_check_death(t_data *dat, t_time philo_time)
{
	t_time	now;

	time_get_now(&now);
	if ((now >= (philo_time + dat->time_die)))
	{
		return (1);
	}
	return (0);
}
