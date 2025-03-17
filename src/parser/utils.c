/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:07:44 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/17 12:37:17 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	count_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	ft_check_for_space(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	len_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_set_data1(t_game *cube, int i, int j)
{
	t_map	*map;

	map = cube->map;
	if (map->map[i][j] == 'W' && map->map[i][j + 1] == 'E' && map->map[i][j
		+ 2] == ' ')
	{
		if (cube->we)
			return ;
		cube->we = ft_strtrim(&map->map[i][j + 2], " ");
	}
	if (map->map[i][j] == 'E' && map->map[i][j + 1] == 'A' && map->map[i][j
		+ 2] == ' ')
	{
		if (cube->ea)
			return ;
		cube->ea = ft_strtrim(&map->map[i][j + 2], " ");
	}
	if (map->map[i][j] == 'S' && map->map[i][j + 1] == 'O' && map->map[i][j
		+ 2] == ' ')
	{
		if (cube->so)
			return ;
		cube->so = ft_strtrim(&map->map[i][j + 2], " ");
	}
}

void	ft_set_data(t_game *cube, int i, int j)
{
	t_map	*map;

	map = cube->map;
	if (map->map[i][j] == 'N' && map->map[i][j + 1] == 'O' && map->map[i][j
		+ 2] == ' ')
	{
		if (cube->no)
			return ;
		cube->no = ft_strtrim(&map->map[i][j + 2], " ");
	}
	ft_set_data1(cube, i, j);
	if (map->map[i][j] == 'F' && map->map[i][j + 1] == ' '
		&& count_commas(map->map[i]) == 2)
		cube->f = ft_split(&map->map[i][j + 2], ',');
	if (map->map[i][j] == 'C' && map->map[i][j + 1] == ' '
		&& count_commas(map->map[i]) == 2)
		cube->c = ft_split(&map->map[i][j + 2], ',');
}
