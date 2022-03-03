/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:26:02 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/03 15:02:23 by lorenuar         ###   ########.fr       */
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

typedef	struct s_philo
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


// TODO remove debug
#include "debug_utils.h"

#define NODEBUGU
#ifndef NODEBUGU
# define return(RET)	\
{dprintf(2, "\033[33;1m%s:%d in %s \033[0m \033[60G|%s R %#-8lx : %-8ld : " #RET "\033[0m\n" , __FILE__, __LINE__, __FUNCTION__,\
(((long)RET) == 0) ? ("\033[32;1m") : ((((long)RET) == 1) ? ("\033[31;1m") : ("\033[0;1m")), ((long)RET), ((long)RET)); return(RET);}
#endif

#undef BM
#define BM(x) _print("Thread ID %p > ", (void *)pthread_self()); _BR_MSG(x); _BR(1);

// # define NOPDAT
# ifndef NOPDAT
#  define PDAT(MSG, X) BM(MSG); print_data(X);
# else
#  define PDAT(MSG, X) ;
# endif

int		str_to_uns(const char *s, t_uns *num);
int		time_get_now(t_time *ptr_time);
int		time_check_death(t_data *dat, t_time philo_time);

int		print_timed_msg(t_phil_dat *pda, char *msg);

int		mutex_lock(pthread_mutex_t *mutex);
int		mutex_unlock(pthread_mutex_t *mutex);

void	msleep(t_time time_ms);

int		spawn_philos(t_data *dat);
void	*philo_thread(void *data);
int		philo_think(t_phil_dat *pdat, t_data *dat);
int		philo_sleep(t_phil_dat *pdat, t_data *dat);
int		philo_eat(t_phil_dat *pdat, t_data *dat);

int		init_data(t_data *dat, int argc, char *argv[]);
int		kill_and_destroy(t_data *dat);

#endif
