/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:00:45 by agaougao          #+#    #+#             */
/*   Updated: 2025/02/22 15:33:06 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_corret_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		i++;
	}
	return (0);
}

int	check_last_wall(char **map)
{
	int	j;
	int	count;
	int	len;
	int	str_lkhr;

	count = 0;
	str_lkhr = get_len(map) - 1;
	len = ft_strlen(map[str_lkhr]);
	j = 0;
	while (map[str_lkhr][j] == '1' || map[str_lkhr][j] == ' ')
	{
		count++;
		j++;
	}
	if (count == len)
		return (1);
	return (0);
}

int	check_sides(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				j++;
			else
				break ;
		}
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_other_side(char **map)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]) - 1;
		while (map[i][len])
		{
			if (map[i][len] == ' ')
				len--;
			else
				break ;
		}
		if (map[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map_wall(t_game *cube)
{
	char	**tmp;
	char	**map;

	tmp = ft_copy_map_to_rect_map(cube->map->map + 6);
	if (!check_first_wall(tmp) || !check_last_wall(tmp) || !check_sides(tmp)
		|| !check_other_side(tmp))
		return (free_all(tmp), 1);
	if (!check_wall_len(tmp))
		return (free_all(tmp), 1);
	free_all(tmp);
	map = ft_copy_map_to_rect_map2(cube->map->map + 6);
	cube->map->width = get_max_width(map);
	cube->map->height = get_len(map);
	free_all(cube->map->map);
	cube->map->map = map;
	return (0);
}
