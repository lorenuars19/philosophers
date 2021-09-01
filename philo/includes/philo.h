/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:26:02 by lorenuar          #+#    #+#             */
/*   Updated: 2021/09/01 22:58:26 by lorenuar         ###   ########.fr       */
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

# define THREADS_MAX 2048

typedef enum e_fork_state
{
	STATE_DEADLOCKED = -1,
	STATE_AVAILABLE = 0,
}	t_fork;

typedef unsigned long long	t_time;
typedef struct s_data
{
	long			n_philo;
	t_time			time_die;
	t_time			time_eat;
	t_time			time_sleep;
	long			max_meals;

	pthread_t		threads[THREADS_MAX + 1];

	t_time			time_until_death[THREADS_MAX + 1];
	t_time			time_spawn[THREADS_MAX + 1];

	t_fork			forks[THREADS_MAX + 1];

	pthread_mutex_t	mutex_fork;

}	t_data;

// TODO remove debug
void	print_data(t_data *dat);

#define NODEBUG 1
#ifndef NODEBUG
#define return(RET)	\
{dprintf(2, "\033[33;1m%s:%d in %s \033[0m \033[60G|%s R %#-8lx : %-8ld : " #RET "\033[0m\n" , __FILE__, __LINE__, __FUNCTION__,\
(((long)RET) == 0) ? ("\033[32;1m") : ((((long)RET) == 1) ? ("\033[31;1m") : ("\033[0;1m")), ((long)RET), ((long)RET)); return(RET);}
#endif /* NODEBUG */


ssize_t	str_to_uns(const char *s);
int		time_get_now(t_time *ptr_time);
void	msleep(t_time time_ms);

int		spawn_manager(t_data *dat);
int		spawn_philos(t_data *dat);


#endif
