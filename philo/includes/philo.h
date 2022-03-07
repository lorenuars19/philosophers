/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:26:02 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/07 09:30:42 by lorenuar         ###   ########.fr       */
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

typedef unsigned long long	t_time;
typedef unsigned long long	t_uns;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*mutex_death;

	t_time			time_die;
	t_time			time_eat;
	t_time			time_sleep;
	t_time			last_meal;

	long			max_meals;
	long			meals;
	long			n_philo;
	int				id;
}			t_phil_dat;

typedef struct s_data
{
	long			n_philo;
	t_time			time_die;
	t_time			time_eat;
	t_time			time_sleep;
	long			max_meals;

	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_death;

	t_phil_dat		*phi_arr;
}	t_data;

int		str_to_uns(const char *s, t_uns *num);
int		time_get_now(t_time *ptr_time);
int		time_check_death(t_data *dat, t_time philo_time);

int		print_timed_msg(t_phil_dat *pda, char *msg);

int		mutex_lock(pthread_mutex_t *mutex);
int		mutex_unlock(pthread_mutex_t *mutex);

void	msleep(t_time time_ms);

int		spawn_threads(t_data *dat);
void	*philo_thread(void *data);

void	check_death(t_data *dat);

int		init_data(t_data *dat, int argc, char *argv[]);
int		kill_and_destroy(t_data *dat);

#endif
