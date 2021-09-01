/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:32:04 by lorenuar          #+#    #+#             */
/*   Updated: 2021/09/01 22:39:40 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*thread_manager(void *data)
{
	(void)data;
	return (((void *)0));
}

int	spawn_manager(t_data *dat)
{

	if (pthread_create(&(dat->threads[0]), NULL, thread_manager, (void *)dat))
		return (1);
	return (0);
}
