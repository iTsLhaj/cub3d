/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:10:19 by agaougao          #+#    #+#             */
/*   Updated: 2025/01/23 18:16:13 by agaougao         ###   ########.fr       */
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

char	**ft_copy_map_to_rect_map(char **map)
{
	char	**map_cpy;
	int		width;
	int		i;
	int		j;

	map_cpy = malloc(sizeof(char *) * (get_len(map) + 1));
	if (!map_cpy)
		return (NULL);
	width = get_max_width(map);
	i = -1;
	while (map && map[++i])
	{
		j = -1;
		map_cpy[i] = malloc(sizeof(char) * (width + 1));
		if (!map_cpy[i])
			return (NULL);
		while (map[i][++j])
			map_cpy[i][j] = map[i][j];
		while (j < width)
			map_cpy[i][j++] = ' ';
		map_cpy[i][j] = '\0';
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

int	check_first_wall(char **map)
{
	int	j;
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(map[0]);
	j = 0;
	while (map[0][j] == '1' || map[0][j] == ' ')
	{
		count++;
		j++;
	}
	if (count == len)
		return (1);
	return (0);
}
