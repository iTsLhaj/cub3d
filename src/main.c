/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:37:08 by agaougao          #+#    #+#             */
/*   Updated: 2024/10/07 16:53:58 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<cub3d.h>

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
void ft_cub3d_init(t_cub3d *cube, char **av)
{
	cube->file = av[1];
	cube->map = get_map(cube->file);
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
	ft_cub3d_init(cube , av);
	return 0;
}
