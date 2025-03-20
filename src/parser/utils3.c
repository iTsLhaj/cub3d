/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:10:19 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/20 00:32:44 by agaougao         ###   ########.fr       */
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

int	check_xpm(char *str)
{
	char	*tmp;

	tmp = ft_strchr(str, '.');
	if (!tmp)
		return (1);
	if (ft_strncmp(tmp, ".xpm", 4) || tmp[4])
		return (1);
	return (0);
}

void	split_space(t_game *cube)
{
	int		i;
	char	*meow;

	i = 0;
	while (cube->map->map[i] && i < 6)
	{
		meow = ft_strtrim(cube->map->map[i], " ");
		free(cube->map->map[i]);
		cube->map->map[i] = meow;
		i++;
	}
}

void	set_compass(t_game *cube)
{
	cube->ea = NULL;
	cube->no = NULL;
	cube->so = NULL;
	cube->we = NULL;
	cube->f = NULL;
	cube->c = NULL;
}
