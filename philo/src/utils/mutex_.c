/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:38:48 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/07 17:26:54 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_lock(pthread_mutex_t *mutex, t_mutex_check *check)
{
	if (check && *check == MUTEX_LOCKED)
	{
//TODO RM DEBUG
dprintf(2,
"\n\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!" "\n"
"     DEADLOCK DETECTED      " "\n"
"!!!!!!!!!!!!!!!!!!!!!!!!!!!!" "\n"
"\n"
);
	return (1);
	}
	if (pthread_mutex_lock(mutex))
	{

BM(mutex_lock ERROR);

		return (1);
	}
	if (check)
	{
		*check = MUTEX_LOCKED;
	}
printf(">MUTEX_LOCK< [%p] %p\n", mutex, *mutex);
	return (0);
}

int	mutex_unlock(pthread_mutex_t *mutex, t_mutex_check *check)
{
	if (pthread_mutex_unlock(mutex))
	{

BM(mutex_unlock ERROR);

		return (1);
	}
	if (check)
	{
		*check = MUTEX_FREE;
	}
printf(">MUTEX_UNLOCK< [%p] %p\n", mutex, *mutex);
	return (0);
}
