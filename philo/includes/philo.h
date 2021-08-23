/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:26:02 by lorenuar          #+#    #+#             */
/*   Updated: 2021/08/23 17:06:26 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define THREADS_MAX 42

typedef struct s_philosopher_data
{
	pthread_t		threads[THREADS_MAX];
	int				returns[THREADS_MAX];
	pthread_mutex_t	mutex;
}	t_pdat;

typedef struct s_thread_data
{
	int				num;
	pthread_mutex_t	*mutex_ptr;
	int				counter;
}	t_tdat;


#endif
