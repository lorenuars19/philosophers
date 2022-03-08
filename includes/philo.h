/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:26:02 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/08 14:46:32 by lorenuar         ###   ########.fr       */
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
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*mutex;

	t_time			start;
	t_time			time_die;
	t_time			time_eat;
	t_time			time_sleep;
	t_time			last_meal;

	long			max_meals;
	long			meals;
	long			n_philo;
	int				id;
	void			*data;
}			t_phil_dat;

typedef struct s_data
{
	t_time			start;
	long			n_philo;
	t_time			time_die;
	t_time			time_eat;
	t_time			time_sleep;
	long			max_meals;

	pthread_mutex_t	mutex;

	t_phil_dat		*phi_arr;
}	t_data;

void	*exec_mutex_safe(t_data *dat, void *arg, void *(*func)(void *));

int		str_to_uns(const char *s, t_uns *num);
t_time	get_time_ms(void);
int		time_check_death(t_data *dat, t_time philo_time);

int		print_timed_msg(t_phil_dat *pda, char *msg);

void	msleep(t_time time_ms);

int		spawn_threads(t_data *dat);
void	*philo_thread(void *data);
void	*set_last_meal(void *data);
void	*increment_meal(void *data);


void	check_threads(t_data *dat);
void	*check_death(void *data);
void	*check_meals(void *data);


int		init_data(t_data *dat, int argc, char *argv[]);
int		kill_and_destroy(t_data *dat);

#endif
