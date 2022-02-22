/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:56:49 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/22 12:01:25 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msleep(t_time time_ms)
{
	t_time	total;
	t_time	big_time;
	t_time	small_times;
	int		i;

	i = 0;
	total = time_ms * 1000;
	big_time = total * 0.8;
	small_times = total * 0.001;
	usleep(big_time);
	while (i < 200)
	{
		usleep(small_times);
		i++;
	}
}
