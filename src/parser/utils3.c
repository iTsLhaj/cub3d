/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:10:19 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/17 13:18:32 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	get_max_width(char **map)
{
	int	i;
	int	width;
	int	len;

	i = 0;
	width = -1;
	while (map && map[i])
	{
		len = ft_strlen(map[i]);
		if (width < len)
			width = len;
		i++;
	}
	return (width);
}

int	get_len(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	return (i);
}
