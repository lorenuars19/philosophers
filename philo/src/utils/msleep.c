/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 22:56:49 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/07 14:26:22 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msleep(t_time time_ms)
{
	t_time	now;

	now = get_time_ms();
	while (get_time_ms() < now + time_ms)
	{
		usleep(500);
	}
}
