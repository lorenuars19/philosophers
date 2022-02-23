/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timed_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:33:44 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/23 14:27:14 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_timed_msg(t_data *dat, int x, const char *msg)
{
	t_time	now;

	if (time_get_now(&now))
	{
		return (1);
	}
	if (mutex_lock(&(dat->mu_print)))
	{
		return (1);
	}
	printf("%lld %d %s\n", now, x, msg);
	if (mutex_unlock(&(dat->mu_print)))
	{
		return (1);
	}
	return (0);
}
