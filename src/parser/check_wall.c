/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:05:20 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/19 23:41:48 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_rest(char *str, int i)
{
	int	len;
	int	count;

	count = 0;
	len = ft_strlen(str) - strlen(&str[i]) + 1;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i--;
	}
	if (count == len)
		return (1);
	return (0);
}

int	check_pos(char **map, int i, int j)
{
	if (map[i + 1])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1')
			{
				if ((map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S')
					|| map[i][j] == 'E' || map[i][j] == 'W')
				{
					if (map[i - 1][j] == ' ')
						return (1);
					if (map[i + 1][j] == ' ')
						return (1);
					if (map[i][j + 1] == ' ')
						return (1);
					if (map[i][j - 1] == ' ')
						return (1);
				}
			}
			j++;
		}
	}
	return (0);
}

int	check_wall_len(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				j++;
			else
			{
				if (check_pos(map, i, j))
					return (0);
				else
					break ;
			}
		}
		i++;
	}
	return (1);
}

int	check_num_colors(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
		if (str[i] == ' ')
			i++;
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-'
				|| str[i] == '+'))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_color(t_game *cube)
{
	cube->ceiling_color = convert_color(cube, 1);
	cube->floor_color = convert_color(cube, 0);
	if (cube->ceiling_color == -1 || cube->floor_color == -1)
		return (1);
	if (check_xpm(cube->ea) || check_xpm(cube->so) || check_xpm(cube->no)
		|| check_xpm(cube->we))
		return (1);
	return (0);
}
