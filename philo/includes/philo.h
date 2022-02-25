/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:26:02 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/25 16:14:49 by lorenuar         ###   ########.fr       */
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

# define THREADS_MAX 512
# define CPU_SAVER 256

typedef enum e_fork_state
{
	FORK_AVAILABLE = -1,
	FORK_HELD_BY_N = 0,
}	t_fork;

typedef enum e_philo_state
{
	STATE_THINKING = 0,
	STATE_TOOK_L_FORK,
	STATE_TOOK_R_FORK,
	STATE_READY_EATING,
	STATE_EATING,
	STATE_SLEEPING,
	STATE_DEAD,
	STATE_MAX,
}	t_phil_state;

typedef unsigned long long	t_time;

typedef	struct s_select_time
{
	t_time	tmp;
	t_time	sel;
	long	sel_ind;
}	t_sel_time;

typedef	struct s_select
{
	int tmp;
	int	sel;
	int	sel_ind;
}	t_sel;

typedef struct s_data
{
	long			n_philo;
	t_time			time_die;
	t_time			time_eat;
	t_time			time_sleep;
	long			max_meals;

	pthread_t		threads[THREADS_MAX];

	t_time			time_last_meal[THREADS_MAX];
	long			meals_consumed[THREADS_MAX];

	t_fork			forks[THREADS_MAX];
	t_phil_state	state[THREADS_MAX];

	pthread_mutex_t	mutex_fork[THREADS_MAX];
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_data;
}	t_data;

typedef	struct s_philo
{
	t_data	*data;
	int		id;
}			t_phil_dat;

typedef unsigned long long t_uns;

// TODO remove debug
void	print_data(t_data *dat);

#define NODEBUGU
#ifndef NODEBUGU
# define return(RET)	\
{dprintf(2, "\033[33;1m%s:%d in %s \033[0m \033[60G|%s R %#-8lx : %-8ld : " #RET "\033[0m\n" , __FILE__, __LINE__, __FUNCTION__,\
(((long)RET) == 0) ? ("\033[32;1m") : ((((long)RET) == 1) ? ("\033[31;1m") : ("\033[0;1m")), ((long)RET), ((long)RET)); return(RET);}
#endif

// # define NOPDAT
# ifndef NOPDAT
#  define PDAT(MSG, X) BM(MSG); print_data(X);
# else
#  define PDAT(MSG, X) ;
# endif

// TODO remove debug
#ifndef STATES_STRINGS
# define STATES_STRINGS
extern const char	*states[STATE_MAX];
#endif

/*
** Utils
*/

int		str_to_uns(const char *s, t_uns *num);
int		time_get_now(t_time *ptr_time);

int		print_timed_msg(t_data *dat, int x, const char *msg);

int		mutex_lock(pthread_mutex_t *mutex);
int		mutex_unlock(pthread_mutex_t *mutex);

void	msleep(t_time time_ms);

int		fork_take(t_data *dat, long philo_id);
int		fork_release(t_data *dat, long philo_id);

int		dat_set_thread(t_data *dat, long philo_id, pthread_t value);
int		dat_get_state(t_data *dat, long philo_id, t_phil_state *state);
int		dat_get_fork(t_data *dat, long philo_id, t_fork *fork);
int		dat_set_state(t_data *dat, long philo_id, t_phil_state state);

int		spawn_philos(t_data *dat);
void	*philo_thread(void *data);
int		philo_think(t_phil_dat *pdat, t_data *dat);
int		philo_sleep(t_phil_dat *pdat, t_data *dat);
int		philo_eat(t_phil_dat *pdat, t_data *dat);

int		manage_threads(t_data *dat, long max_meals);
int 	check_philo_death(t_data *dat);
int		let_philos_eat(t_data *dat);


int		init_data(t_data *dat, int argc, char *argv[]);
int		kill_and_destroy(t_data *dat);

#endif
