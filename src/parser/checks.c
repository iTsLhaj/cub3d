/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:05:51 by agaougao          #+#    #+#             */
/*   Updated: 2025/02/22 14:55:14 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_arg(int ac, char **av)
{
	char	*tmp;

	if (ac != 2)
		return (1);
	tmp = ft_strchr(av[1], '.');
	if (!tmp)
		return (1);
	if (ft_strncmp(tmp, ".cub", 4) || tmp[4])
		return (1);
	return (0);
}

char	**get_map(char *file)
{
	int		fd;
	char	**map;
	char	*str;
	char	*ptr;

	ptr = ft_calloc(1, 1);
	fd = open(file, O_RDWR);
	str = get_next_line(fd);
	if (str == NULL)
		perror("empty file\n");
	while (str)
	{
		if (str == NULL)
			break ;
		ptr = ft_strjoin(ptr, str);
		free(str);
		str = get_next_line(fd);
	}
	map = ft_split(ptr, '\n');
	free(ptr);
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

	i = 0;
	map = cube->map;
	while (map->map[i] && i < 6)
	{
		if (map->map[i][0] == 'N' || map->map[i][0] == 'S'
			|| map->map[i][0] == 'E' || map->map[i][0] == 'W'
			|| map->map[i][0] == 'F' || map->map[i][0] == 'C')
			ft_set_data(cube, i, 0);
		else
			return (1);
		i++;
	}
	if (!cube->no || !cube->we || !cube->ea || !cube->so || !cube->c
		|| !cube->f)
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

	i = 0;
	cube->map = (t_map *)malloc(sizeof(t_map));
	cube->file = av[1];
	cube->ea = NULL;
	cube->no = NULL;
	cube->so = NULL;
	cube->we = NULL;
	cube->f = NULL;
	cube->c = NULL;
	cube->map->map = get_map(cube->file);
	while (cube->map->map[i])
		i++;
	if (i < 5)
		return (1);
	if (check_compass(cube))
		return (1);
	if (check_char(cube->map->map))
		return (1);
	if (check_map_wall(cube))
		return (1);
	cube->ceiling_color = convert_color(cube);
	cube->floor_color = convert_color(cube);
	return (0);
}
