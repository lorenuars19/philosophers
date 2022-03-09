/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:32:08 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/09 10:00:52 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_usage(char *msg, char *prog)
{
	printf("\033[31;1m%s\033[0m\n=== Usage ===\n"
		" %s [number_of_philo] [time_to_die(ms)]"
		" [time_to_eat(ms)] [time_to_sleep(ms)]"
		" [maximum_number_of_meals (optional)] \n=============\n",
		msg,
		prog);
	return (1);
}

static void	print_stats(t_data *dat)
{
	int	i;

	i = 0;
	printf("=== PHILO STATS ===\n");
	while (i < dat->n_philo)
	{
		printf("philo [i %d] meals %ld last_meal %llu\n", i,
			dat->phi_arr[i].meals, dat->phi_arr[i].last_meal);
		i++;
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
	if (spawn_threads(&dat))
	{
		return (1);
	}
	if (DEBUG == 1)
	{
		print_stats(&dat);
	}
	if (kill_and_destroy(&dat))
	{
		return (1);
	}
	return (0);
}
