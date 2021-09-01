/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:26:02 by lorenuar          #+#    #+#             */
/*   Updated: 2021/09/01 10:50:47 by lorenuar         ###   ########.fr       */
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

# define THREADS_MAX 256

typedef enum e_fork_state
{
	STATE_DEADLOCKED = -1,
	STATE_AVAILABLE = 0,
}	t_fork;

typedef unsigned long	t_time;
typedef struct s_data
{
	long		n_philo;
	t_time		time_die;
	t_time		time_eat;
	t_time		time_sleep;
	long		max_meals;

	pthread_t	thread_ids[THREADS_MAX];

	t_time		time_until_death[THREADS_MAX];

	t_fork		forks[THREADS_MAX];
}	t_data;

/* debug */
void	print_data(t_data *dat);


ssize_t	str_to_nbr(const char *s);

#endif
