/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 21:51:29 by lorenuar          #+#    #+#             */
/*   Updated: 2021/09/01 22:28:10 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread_philo(void *data); //TODO remove

int	spawn_philos(t_data *dat)
{
	int	i;

	i = 1;
	while (i <= dat->n_philo)
	{
		if (pthread_create(&(dat->threads[i]), NULL, thread_philo, (void *)dat))
			return (1);

		i++;
	}
	return (0);
}

#undef return	//TODO remove

void	*thread_philo(void *data)
{
	(void)data;
	return ((void *)0);
}
