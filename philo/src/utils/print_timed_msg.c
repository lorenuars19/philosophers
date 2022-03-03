/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timed_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:33:44 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/03 16:42:36 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_timed_msg(t_phil_dat *pda, char *msg)
{
	t_time		now;

	if (time_get_now(&now))
	{
		return (1);
	}
	if (mutex_lock(pda->mutex_print))
	{
		return (1);
	}
	printf("%lld %02d %s\n", now, pda->id + 1, msg);
	if (mutex_unlock(pda->mutex_print))
	{
		return (1);
	}
	return (0);
}
