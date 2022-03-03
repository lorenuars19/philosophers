/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:11:05 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/03 11:11:19 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	destroy_mutexes(t_data *dat)
{
	if (pthread_mutex_destroy(&(dat->mutex_print)))
	{
		return (1);
	}
	return (0);
}

int	kill_and_destroy(t_data *dat)
{
	if (destroy_mutexes(dat))
	{
		return (1);
	}
	return (0);
}
