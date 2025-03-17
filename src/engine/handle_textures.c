/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:44:49 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/17 12:33:24 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	convert_color(t_game *cube, int fc)
{
	int	red;
	int	green;
	int	blue;

	if (!check_num_colors(cube->c[0]) || !check_num_colors(cube->c[1])
		|| !check_num_colors(cube->c[2]) || !check_num_colors(cube->f[0])
		|| !check_num_colors(cube->f[1]) || !check_num_colors(cube->f[2]))
		return (-1);
	if (fc)
	{
		red = ft_atoi(cube->c[0]);
		green = ft_atoi(cube->c[1]);
		blue = ft_atoi(cube->c[2]);
	}
	else
	{
		red = ft_atoi(cube->f[0]);
		green = ft_atoi(cube->f[1]);
		blue = ft_atoi(cube->f[2]);
	}
	if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0
		|| blue > 255)
		return (-1);
	return (red << 16 | green << 8 | blue);
}

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

int	size_texture(int width, int height)
{
	if (width != 64 || height != 64)
	{
		return (1);
	}
	return (0);
}

t_img	*put_img_add(t_game *game, char *path)
{
	t_img	*img;
	int		height;
	int		width;

	height = 0;
	width = 0;
	img = ft_calloc(1, sizeof(t_img));
	if (!img)
	{
		ft_putstr_fd("Error: malloc failed\n", 2);
		return (NULL);
	}
	img->img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!img->img || size_texture(width, height) == 1)
	{
		ft_putstr_fd("Error: could not load texture\n", 2);
		free(img);
		ft_end(game);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->size_line), &(img->endian));
	return (img);
}

void	get_texture(t_game *game)
{
	game->texture_buffer[0] = put_img_add(game, game->no);
	game->texture_buffer[1] = put_img_add(game, game->so);
	game->texture_buffer[2] = put_img_add(game, game->ea);
	game->texture_buffer[3] = put_img_add(game, game->we);
}
