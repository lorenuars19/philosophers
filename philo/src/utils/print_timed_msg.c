/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timed_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:33:44 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/08 18:40:27 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_timed_msg(t_phil_dat *pda, char *msg)
{
	if (pda->mutex == NULL)
	{
		return (0);
	}
	if (pthread_mutex_lock(pda->mutex))
	{
		return (1);
	}
	if (!pda->is_dead)
	{
		printf("%lld %d %s\n", get_time_ms() - pda->start, pda->id + 1, msg);
	}
	if (pthread_mutex_unlock(pda->mutex))
	{
		return (1);
	}
	return (0);
}
