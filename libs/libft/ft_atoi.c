/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:37:53 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/14 15:35:29 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	unsigned long int	result;
	int					sign;

	result = 0;
	sign = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'
			|| *str == '\r' || *str == '\f'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - 48);
		if (result >= LONG_MAX && sign == 1)
			return (-1);
		if (result > LONG_MAX && sign == -1)
			return (0);
		str++;
	}
	return (result * sign);
}
