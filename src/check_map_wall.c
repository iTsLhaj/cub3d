/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:00:45 by agaougao          #+#    #+#             */
/*   Updated: 2024/10/27 16:48:13 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<cub3d.h>

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
int check_corret_map(char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			j++;
		}
		i++;
	}
	return (0);
}

int	check_first_wall(char **map)
{
	int	i;
	int	j;
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(map[0]);
	i = 0;
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

int	check_last_wall(char **map)
{
	int	i;
	int	j;
	int	count;
	int	len;
	int	str_lkhr;

	count = 0;
	str_lkhr = get_len(map) - 1;
	len = ft_strlen(map[str_lkhr]);
	i = 0;
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
	int	len;

	i = 1;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == ' ')
				j++;
			else
				break;
		}
		if(map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}
int check_other_side(char **map)
{
	int i;
	int len;

	i = 0;
	while(map[i])
	{
		len = ft_strlen(map[i]) - 1;
		while(map[i][len])
		{
			if(map[i][len] == ' ')
				len--;
			else
				break;
		}
		if(map[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}
int check_map_wall(t_cub3d *cube)
{
	int i;
	char **tmp;

	i = 0;
	tmp = ft_copy_map_to_rect_map(cube->map + 6);
	if(!check_first_wall(tmp) || !check_last_wall(tmp)
		|| !check_sides(tmp) || !check_other_side(tmp))
		return (1);

	if(!check_wall_len(tmp))
		return (1);
	return(0);
}
