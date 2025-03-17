/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:10:19 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/17 13:15:48 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	fill_and_padd(char **map, char *line, int j, int i)
{
	int	width;

	width = get_max_width(map);
	while (map[i][++j] == ' ')
		line[j] = '1';
	while (map[i][j])
	{
		line[j] = map[i][j];
		j++;
	}
	while (j < width)
		line[j++] = '1';
	line[j] = '\0';
	return (j);
}

char	**ft_copy_map_to_rect_map2(char **map)
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
		j = fill_and_padd(map, map_cpy[i], j, i);
	}
	map_cpy[i] = NULL;
	return (map_cpy);
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
