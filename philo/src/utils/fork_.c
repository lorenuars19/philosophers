/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:49:27 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 13:51:09 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dbg_print_fork(t_data *dat, long philo_id)
{
	static char	*state_strings[STATE_MAX] = {
		"THINKING",
		"REQUEST_L_FORK",
		"REQUEST_R_FORK",
		"TOOK_L_FORK",
		"TOOK_R_FORK",
		"REQUEST_EATING",
		"EATING",
		"RELEASED_L_FORK",
		"RELEASED_R_FORK",
		"SLEEPING",
		"DEAD"
		};

	printf("PHI ID %ld | STATE %s\n",
		philo_id,
		state_strings[dat->state[philo_id]]);
}

int	fork_take(t_data *dat, long philo_id)
{
dbg_print_fork(dat, philo_id);
	return (0);
}

int	fork_release(t_data *dat, long philo_id)
{
dbg_print_fork(dat, philo_id);
	return (0);
}
