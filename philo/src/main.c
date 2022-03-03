/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:32:08 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/03 15:27:00 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define NODEBUGU

static int	print_usage(char *msg, char *prog)
{
	printf("\033[31;1m%s\033[0m\n=== Usage ===\n"
		" %s [number_of_philo] [time_to_die(ms)]"
		" [time_to_eat(ms)] [time_to_sleep(ms)]"
		" [maximum_number_of_meals (optional)] \n=============\n",
		msg, prog);
	return (1);
}

static void	check_death(t_data *dat)
{
	int	i;
	int	dead;

	dead = 0;
	while (!dead)
	{
		i = 0;
		while (i < dat->n_philo)
		{
			dead = time_check_death(dat, dat->phi_arr[i].last_meal);
			if (dead)
			{
				if (dat->max_meals == 0)
				{
					print_timed_msg(&(dat->phi_arr[i]), "is dead");
				}
				mutex_lock(&(dat->mutex_print));
				return ;
			}
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data	dat;

	if (!(argc == 5 || argc == 6))
	{
		print_usage("Invalid number of arguments", argv[0]);
		return (1);
	}
	if (init_data(&dat, argc, argv))
	{
		print_usage("Error from init_data()", argv[0]);
		return (1);
	}
	if (spawn_philos(&dat))
	{
		return (1);
	}
	check_death(&dat);
	if (kill_and_destroy(&dat))
	{
		return (1);
	}
	return (0);
}
