/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timed_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:33:44 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/25 13:34:45 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

const char	*states[STATE_MAX] = {
		"is thinking",
		"has taken L fork",
		"has taken R fork",
		"is eating",
		"SLEEPING",
		"DEAD"};

int	print_timed_msg(t_data *dat, int x, const char *msg)
{
	t_time	now;

	if (time_get_now(&now))
	{
		return (1);
	}
	if (mutex_lock(&(dat->mutex_print)))
	{
		return (1);
	}
	printf("%lld %d %s\n", now, x + 1, msg);
	if (mutex_unlock(&(dat->mutex_print)))
	{
		return (1);
	}
	return (0);
}
