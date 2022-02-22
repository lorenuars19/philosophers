/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:32:08 by lorenuar          #+#    #+#             */
/*   Updated: 2022/02/22 16:25:47 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_usage(char *prog)
{
	printf("=== Usage ===\n"
			" %s [number_of_philo] [time_to_die(ms)]"
			" [time_to_eat(ms)] [time_to_sleep(ms)]"
			" [maximum_number_of_meals (optional)] \n=============\n",
			prog);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	dat;

	if (!(argc == 5 || argc == 6))
	{
		print_usage(argv[0]);
		return (1);
	}
	if (init_data(&dat, argc, argv))
	{
		print_usage(argv[0]);
		return (1);
	}
PDAT(main before spawn_philos, &dat); // TODO remove debug
	if (spawn_philos(&dat))
	{
		return (1);
	}
PDAT(main before manage_threads, &dat); // TODO remove debug
	if (manage_threads(&dat))
	{
		return (1);
	}
PDAT(main before kill_and_destroy, &dat); // TODO remove debug
	if (kill_and_destroy(&dat))
	{
		return (1);
	}
PDAT(main END, &dat); // TODO remove debug
	return (0);
}
