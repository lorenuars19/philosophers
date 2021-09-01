/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:00:31 by lorenuar          #+#    #+#             */
/*   Updated: 2021/09/01 18:27:44 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
