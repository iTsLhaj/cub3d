/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:00:45 by agaougao          #+#    #+#             */
/*   Updated: 2024/10/21 15:49:40 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<cub3d.h>

static int	get_max_width(char **map)
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

static int	get_len(char **map)
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
int check_

int check_map_wall(t_cub3d *cube)
{
	int i;
	char **tmp;

	i = 0;
	tmp = ft_copy_map_to_rect_map(cube->map + 6);

	return(0);
}
