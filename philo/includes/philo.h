/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:26:02 by lorenuar          #+#    #+#             */
/*   Updated: 2021/09/07 14:49:52 by lorenuar         ###   ########.fr       */
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

#include "debug_utils.h"

# define THREADS_MAX 1024

# define CPU_SAVER 2

typedef enum e_fork_state
{
	FORK_DEADLOCKED = -2,
	FORK_AVAILABLE = -1,
	FORK_HELD_BY_N = 0,
}	t_fork;

typedef enum e_philo_state
{
	STATE_THINKING = 0,
	STATE_EATING,
	STATE_SLEEPING,
	STATE_DEAD,
}	t_philo;

typedef unsigned long long	t_time;

typedef	struct s_select_time
{
	t_time	tmp;
	t_time	sel;
	long	sel_ind;
}	t_sel_time;


typedef struct s_data
{
	long			n_philo;
	t_time			time_die;
	t_time			time_eat;
	t_time			time_sleep;
	long			max_meals;

	pthread_t		threads[THREADS_MAX];

	t_time			time_until_death[THREADS_MAX];
	t_time			time_last_meal[THREADS_MAX];

	t_fork			forks[THREADS_MAX];
	t_philo			state[THREADS_MAX];

	pthread_mutex_t	mutex_fork[2];
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_data;

}	t_data;

typedef	struct s_philo
{
	t_data	*data;
	int		id;
}			t_phil_dat;


// TODO remove debug
void	print_data(t_data *dat);

// #define NODEBUG 1
#ifndef NODEBUG
#define return(RET)	\
{dprintf(2, "\033[33;1m%s:%d in %s \033[0m \033[60G|%s R %#-8lx : %-8ld : " #RET "\033[0m\n" , __FILE__, __LINE__, __FUNCTION__,\
(((long)RET) == 0) ? ("\033[32;1m") : ((((long)RET) == 1) ? ("\033[31;1m") : ("\033[0;1m")), ((long)RET), ((long)RET)); return(RET);}
#endif /* NODEBUG */

ssize_t	str_to_uns(const char *s);
int		time_get_now(t_time *ptr_time);
void	msleep(t_time time_ms);

int		spawn_philos(t_data *dat);
int		manage_threads(t_data *dat);


#endif
