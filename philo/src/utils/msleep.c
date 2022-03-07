/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:56:49 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/07 09:47:54 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msleep(t_time time_ms)
{
	t_time	total;
	t_time	big_time;
	int		pooling_times;
	int		i;

	i = 0;
	total = time_ms * 1000LL;
	pooling_times = 500;
	big_time = total - (pooling_times * 1000LL);
	usleep(big_time);
	while (i < pooling_times)
	{
		usleep(pooling_times);
		i++;
	}
}
