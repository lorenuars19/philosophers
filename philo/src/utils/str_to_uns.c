/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:00:31 by lorenuar          #+#    #+#             */
/*   Updated: 2021/10/01 15:24:38 by lorenuar         ###   ########.fr       */
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

int	str_to_uns(const char *s, t_ul *num)
{
	if (!num || !s)
	{
		return (1);
	}
	*num = 0;
	while (s && *s && is_wsp(*s))
	{
		s++;
	}
	if (s && (*s < '0' || *s > '9'))
	{
		return (1);
	}

	while (num && s && *s >= '0' && *s <= '9')
		*num = ((*num) * 10) + (*s++ - '0');
	if (num && *num > ULONG_MAX)
	{
		*num = 0;
		return (0);
	}
	return (0);
}
