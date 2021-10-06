/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:19:49 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/06 19:08:10 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	wait_for_action(t_phil_dat *pdat, t_data *dat)
{
	t_phil_state	state;

	while (pdat->wait_for_action)
	{
		if (dat_get_state(dat, pdat->id, &(state)))
		{
			return (1);
		}
		if (state != STATE_DEAD)
		{
			return (0);
		}
	}
	return (0);
}

int	fd[THREADS_MAX];

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

# define pfile(fmt, ... ) dprintf(fd[pdat->id] , fmt, ##__VA_ARGS__ );

#define ERR dprintf(2, "ERR PHILO N %d L %d\n", pdat->id, __LINE__);

static void	print_log_file_init(void *data, t_phil_dat *pdat, t_data *dat, const char *msg)
{
	char	filename[1024];

	if (mutex_lock(&(dat->mutex_data)))
	{
		return ;
	}

	if (pdat->id >= 0 && pdat->id < THREADS_MAX)
	{
		fd[pdat->id] = 2;
		if (!(snprintf(filename, 1024, "logs/.philo_%d_log", pdat->id)))
		{
			ERR;
		}
		fd[pdat->id] = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0664);
		if (fd < 0)
		{
			ERR;
		}
		dprintf(2, "RESULT %s | ERR %d %s | fd[id %d] %d\n", filename, errno, strerror(errno), pdat->id, fd[pdat->id]);
		pfile("%d {%s}", pdat->id, msg);
	}
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return ;
	}

	return ;
}
static void	print_log_file(void *data, t_phil_dat *pdat, t_data *dat, const char *msg)
{

	return ;
}

static void	print_log_file_end(void *data, t_phil_dat *pdat, t_data *dat, const char *msg)
{
	if (mutex_lock(&(dat->mutex_data)))
	{
		return ;
	}
	if (pdat->id >= 0 && pdat->id < THREADS_MAX)
	{
		close(fd[pdat->id]);
	}
	if (mutex_unlock(&(dat->mutex_data)))
	{
		return ;
	}
}


#define PLOG_INIT(X) print_log_file_init(data, pdat, dat, #X);

#define PLOG(X)	\
if (pdat->id >= 0 && pdat->id < THREADS_MAX){\
t_time	time; time_get_now(&time); \
pfile("<%lld> %s:%s::%d\n\t data %p\n", time, __FILE__, __LINE__, data);} \


#define PLOG_END(X) print_log_file_end(data, pdat, dat, #X);


void	*philo_thread(void *data)
{
	t_phil_dat	*pdat;
	t_data		*dat;

	pdat = ((t_phil_dat *)data);
	dat = pdat->data;

// PLOG_INIT(START_PHILO)


	if (wait_for_action(pdat, dat))
	{
		return (NULL);
	}
// PLOG(Finished waiting);


	// if (dat_set_thread(dat, pdat->id, (pthread_t)0)) // END, protect joins from dead threads
	// {
	// 	// Error
	// }
PLOG_END(START_PHILO)
	return (NULL);
}
