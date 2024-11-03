/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:37:08 by agaougao          #+#    #+#             */
/*   Updated: 2024/11/03 08:21:11 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<cub3d.h>

int check_char(char **map)
{
	int i;
	int j;
	int p_count;

	i = 6;
	p_count = 0;
	
	while (map[i])
	{	
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'N'
				&& map[i][j] != 'S'	&& map[i][j] != 'E' && map[i][j] != 'W'
					&& map[i][j] != ' ')
				{
					puts(&map[i][j]);	
					return (1);
				}
			if(map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				p_count++;
			}
			j++;
		}
		i++;
	}
	if(p_count == 1)
		return (0);
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
	while (cube->map[i] && i < 6)
	{
		if (cube->map[i][0] == 'N' || cube->map[i][0] == 'S'
			|| cube->map[i][0] == 'E' || cube->map[i][0] == 'W'
			|| cube->map[i][0] == 'F' || cube->map[i][0] == 'C')
			ft_set_data(cube, i, 0);
		else
		 return (1);
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

int convert_color(t_cub3d *cube)
{
	int red;
    int green;
    int blue;

    red = ft_atoi(cube->c[0]);
    green = ft_atoi(cube->c[1]);
    blue = ft_atoi(cube->c[2]);
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255)
        return (-1);
    return (red << 16 | green << 8 | blue);
}

int check_map(t_cub3d *cube, char **av)
{
	int i;

	i = 0;
	cube->file = av[1];
	cube->ea = NULL;
	cube->no = NULL;
	cube->so = NULL;
	cube->we = NULL;
	cube->f = NULL;
	cube->c = NULL;
	cube->map = get_map(cube->file);
	while(cube->map[i])
		i++;
	if(i < 5)
		return(1);
	if(check_compass(cube))
		return (1);
	if(check_char(cube->map))
		return (1);
	if(check_map_wall(cube))
		return (1);
	cube->ceiling_color = convert_color(cube);
	cube->floor_color = convert_color(cube);
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
	t_gcollector collector;
	t_gcollector *cp;

	cp = &collector;
	ft_bzero(cp, sizeof(t_gcollector));
	cube = malloc(sizeof(t_cub3d));
	if(check_arg(ac , av))
		return(ft_putstr_fd("failed on argument\n",2), 1);
	if(check_map(cube , av))
	    return(ft_putstr_fd("failed on map\n",2), 1);
	gc_free(&cp);
	return 0;
}
