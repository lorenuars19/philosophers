/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timed_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:33:44 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/07 13:17:17 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_timed_msg(t_phil_dat *pda, char *msg)
{
	t_data	*data;

	data = (t_data *)pda->data;
	if (mutex_lock(pda->mutex_print))
	{
		return (1);
	}
	printf("%016lld %02d %s\n", get_time_ms() - data->start, pda->id + 1, msg);
	if (mutex_unlock(pda->mutex_print))
	{
		return (1);
	}
	return (0);
}
