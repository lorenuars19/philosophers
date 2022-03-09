/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_mutex_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:56:27 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/08 14:04:07 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*exec_mutex_safe(t_data *dat, void *arg, void *(*func)(void *))
{
	void	*ret;

	if (pthread_mutex_lock(&(dat->mutex)))
	{
		return (NULL);
	}
	ret = func(arg);
	if (pthread_mutex_unlock(&(dat->mutex)))
	{
		return (NULL);
	}
	return (ret);
}
