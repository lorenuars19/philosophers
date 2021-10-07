/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timed_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:33:44 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 16:49:46 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_timed_msg(t_data *dat, int x, char *msg)
{
	t_time	now;

	if (time_get_now(&now))
	{
		return (1);
	}
	ML; if (mutex_lock(&(dat->mutex_print), &(dat->check_print)))
	{
		return (1);
	}
	printf("%lld %d %s\n", now, x, msg);
	MU; if (mutex_unlock(&(dat->mutex_print), &(dat->check_print)))
	{
		return (1);
	}
	return (0);
}
