/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:38:48 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/06 19:06:49 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#undef mutex_lock
#undef mutex_unlock

int	mutex_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex))
	{

BM(mutex_lock ERROR);

		return (1);
	}
	return (0);
}

int	mutex_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex))
	{

BM(mutex_unlock ERROR);

		return (1);
	}
	return (0);
}
