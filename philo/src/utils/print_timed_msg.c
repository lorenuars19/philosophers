/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timed_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:33:44 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/28 17:40:32 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_timed_msg(t_data *dat, int x, t_phil_state state)
{
	t_time		now;
	static char	*states[STATE_MAX] = {
		"is thinking",
		"has taken L fork",
		"has taken R fork",
		"is ready to eat"
		"is eating",
		"is sleeping",
		"W T F",
		"is dead"};

	if (time_get_now(&now))
	{
		return (1);
	}
	if (mutex_lock(&(dat->mutex_print)))
	{
		return (1);
	}
	printf("%lld %d %s DBG %d\n", now, x + 1, states[state], state);
	if (mutex_unlock(&(dat->mutex_print)))
	{
		return (1);
	}
	return (0);
}
