/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:00:31 by lorenuar          #+#    #+#             */
/*   Updated: 2021/09/17 15:10:42 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NODEBUG 1
#include "philo.h"
#include <limits.h>


static int	is_wsp(char c)
{
	if (c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

ssize_t	str_to_uns(const char *s)
{
	unsigned long	num;

	num = 0;
	while (s && *s && is_wsp(*s))
		s++;
	while (s && *s >= '0' && *s <= '9')
		num = (num * 10) + (*s++ - '0');
	if (num > ULONG_MAX)
	{
		return (0);
	}
	return (num);
}
