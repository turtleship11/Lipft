/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeklee <jaeklee@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:34:11 by jaeklee           #+#    #+#             */
/*   Updated: 2025/04/21 15:44:36 by jaeklee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *str)
{
	int		c;
	long	v;

	c = 1;
	v = 0;
	if (!str)
		return (0);
	while (*str == ' ' || (*str >= 8 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			c = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		v = v * 10 + (*str - '0');
		str++;
	}
	return (v * c);
}
