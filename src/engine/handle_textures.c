/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:44:49 by agaougao          #+#    #+#             */
/*   Updated: 2025/01/23 18:28:30 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	if (!img->img || size_texture(width, height) == 1 || !path)
	{
		ft_putstr_fd("Error: could not load texture\n", 2);
		free(img);
		exit(1);
	}
	puts("here\n");
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
