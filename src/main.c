/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:37:08 by agaougao          #+#    #+#             */
/*   Updated: 2024/10/16 17:10:50 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<cub3d.h>

int check_char(char **map)
{
	int i;
	int j;
	int p_count;

	i = 0;
	p_count = 0;
	while (map[i])
	{
		if( map[i][0] == 'N' || map[i][0] == 'S' || map[i][0] == 'E'
			|| map[i][0] == 'W' || map[i][0] == 'F' || map[i][0] == 'C'
			|| map[i][0] == '\n')
			i++;
		else
		{
			j = 0;
			while(map[i][j])
			{
				if(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == ' ')
				{
					if(map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
						&& map[i][j] != 'S'	&& map[i][j] != 'E' && map[i][j] != 'W'
							&& map[i][j] != ' ')
							return (0);
					else if( map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
						|| map[i][j] == 'W')
						p_count++;
					if(p_count != 1 && p_count != 0)
						return (0);
				}
				j++;
			}
		}
		i++;
	}
	return (1);
}

char **get_map(char *file)
{
	int fd;
	char **map;
	char *str;
	char *ptr;

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
	map = ft_split(ptr,'\n');
	free(ptr);
	return(map);
}
void ft_set_data(t_cub3d *cube , int i , int j)
{
	if(cube->map[i][j] == 'N' && cube->map[i][j + 1] == 'O'
			&& cube->map[i][j + 2] == ' ')
		cube->no = ft_strtrim(&cube->map[i][j + 2], " ");
	if(cube->map[i][j] == 'W' && cube->map[i][j + 1] == 'E'
			&& cube->map[i][j + 2] == ' ')
		cube->we = ft_strtrim(&cube->map[i][j + 2], " ");
	if(cube->map[i][j] == 'E' && cube->map[i][j + 1] == 'A'
			&& cube->map[i][j + 2] == ' ')
		cube->ea = ft_strtrim(&cube->map[i][j + 2], " ");
	if(cube->map[i][j] == 'S' && cube->map[i][j + 1] == 'O'
			&& cube->map[i][j + 2] == ' ')
		cube->so = ft_strtrim(&cube->map[i][j + 2], " ");
	if(cube->map[i][j] == 'F' && cube->map[i][j + 1] == ' '
			&&  count_commas(cube->map[i]) == 2)
		cube->f = ft_split(&cube->map[i][j + 2], ',');
	if(cube->map[i][j] == 'C' && cube->map[i][j + 1] == ' '
			&&  count_commas(cube->map[i]) == 2)
		cube->c = ft_split(&cube->map[i][j + 2], ',');
}

int check_compass(t_cub3d *cube)
{
	int i;

	i = 0;
	while (cube->map[i])
	{
		if (cube->map[i][0] == 'N' || cube->map[i][0] == 'S'
			|| cube->map[i][0] == 'E' || cube->map[i][0] == 'W'
			|| cube->map[i][0] == 'F' || cube->map[i][0] == 'C')
			ft_set_data(cube, i, 0);
		i++;
	}
	if (!cube->no ||!cube->we ||!cube->ea ||!cube->so || !cube->c
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

int check_map(t_cub3d *cube, char **av)
{
	cube->file = av[1];
	cube->ea = NULL;
	cube->no = NULL;
	cube->so = NULL;
	cube->we = NULL;
	cube->f = NULL;
	cube->c = NULL;
	cube->map = get_map(cube->file);
	if(check_compass(cube))
		return (1);
	if(check_char(cube->map) == 0)
		return (1);
	if(!check_map_wall(cube))
		return (1);
	return (0);
}
int check_arg(int ac , char **av)
{
	char *tmp;
	if (ac != 2)
		return (1);
	tmp = ft_strchr(av[1], '.');
	if (!tmp)
		return (1);
	if (ft_strncmp(tmp, ".cub", 4) || tmp[4])
		return (1);
	return (0);
}
int main(int ac , char **av)
{
	t_cub3d *cube;

	cube = malloc(sizeof(t_cub3d));
	if(check_arg(ac , av))
		return(ft_putstr_fd("failed on argument\n",2), 1);
	if(check_map(cube , av))
	    return(ft_putstr_fd("failed on map\n",2), 1);
	return 0;
}
