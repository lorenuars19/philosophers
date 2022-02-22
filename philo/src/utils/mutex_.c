/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:38:48 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/22 17:07:56 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_lock(pthread_mutex_t *mutex)
{
	if (mutex && pthread_mutex_lock(mutex))
	{
		return (1);
	}
	return (0);
}

int	mutex_unlock(pthread_mutex_t *mutex)
{
	if (mutex && pthread_mutex_unlock(mutex))
	{
		return (1);
	}
	return (0);
}
