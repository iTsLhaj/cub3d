/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:05:51 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/20 00:33:41 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	check_for_double(char **map, char *tmp, t_map *tmap)
{
	int		i;
	char	*tmp2;

	i = -1;
	while (map && map[++i] && i < 6)
		;
	if (i == 6 && map[i])
		tmp2 = ft_strnstr(tmp, map[i], ft_strlen(tmp));
	else
		return ;
	i = -1;
	while (tmp2 && tmp2[++i])
	{
		if (tmp2[i] == '\n' && tmp2[i + 1] == '\n')
		{
			free_all(map);
			free(tmp);
			free(tmap);
			(ft_putstr_fd("Error\nWrong map\n", 2), exit(1));
		}
	}
}

char	**get_map(char *file, t_map *tmap)
{
	int		fd;
	char	**map;
	char	*str;
	char	*ptr;
	char	*new_ptr;

	ptr = ft_calloc(1, 1);
	fd = open(file, O_RDWR);
	str = get_next_line(fd);
	while (str)
	{
		new_ptr = ft_strjoin(ptr, str);
		free(ptr);
		free(str);
		ptr = new_ptr;
		str = get_next_line(fd);
	}
	map = ft_split(ptr, '\n');
	check_for_double(map, ptr, tmap);
	free(ptr);
	close(fd);
	return (map);
}

int	check_char(char **map)
{
	int	i;
	int	j;
	int	p_count;

	i = 6;
	p_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
				&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W'
				&& map[i][j] != ' ')
				return (1);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				p_count++;
			j++;
		}
		i++;
	}
	if (p_count == 1)
		return (0);
	return (1);
}

int	check_compass(t_game *cube)
{
	int		i;
	t_map	*map;

	i = -1;
	map = cube->map;
	while (map->map[++i] && i < 6)
	{
		if (map->map[i][0] == 'N' || map->map[i][0] == 'S'
			|| map->map[i][0] == 'E' || map->map[i][0] == 'W'
			|| map->map[i][0] == 'F' || map->map[i][0] == 'C')
			ft_set_data(cube, i, 0);
		else
			return (1);
	}
	if (!cube->no || !cube->we || !cube->ea || !cube->so || !cube->c || !cube->f
		|| !cube->c[0] || !cube->c[1] || !cube->c[2] || !cube->f[0]
		|| !cube->f[1] || !cube->f[2])
		return (1);
	if (ft_check_for_space(cube->no) || ft_check_for_space(cube->so)
		|| ft_check_for_space(cube->we) || ft_check_for_space(cube->ea)
		|| ft_check_for_space(cube->f[0]) || ft_check_for_space(cube->f[1])
		|| ft_check_for_space(cube->f[2]) || ft_check_for_space(cube->c[0])
		|| ft_check_for_space(cube->c[1]) || ft_check_for_space(cube->c[2]))
		return (1);
	return (0);
}

int	check_map(t_game *cube, char **av)
{
	int	i;

	i = -1;
	cube->map = (t_map *)malloc(sizeof(t_map));
	cube->file = av[1];
	set_compass(cube);
	cube->map->map = get_map(cube->file, cube->map);
	split_space(cube);
	while (cube->map->map[++i])
		;
	if (i < 5)
		return (1);
	if (check_compass(cube))
		return (1);
	if (check_char(cube->map->map))
		return (1);
	if (check_map_wall(cube))
		return (1);
	if (check_color(cube))
		return (1);
	return (0);
}
