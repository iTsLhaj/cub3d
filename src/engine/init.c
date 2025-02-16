/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:31:40 by agaougao          #+#    #+#             */
/*   Updated: 2025/01/23 18:32:25 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/** @todo recheck the compass ! */
static double	get_player(char *c)
{
	double	dir;

	if (ft_strchr("NWSE", *c) == NULL)
		return (-1.0f);
	else
	{
		if (*c == 'E')
			dir = 0;
		else if (*c == 'N')
			dir = M_PI / 2;
		else if (*c == 'W')
			dir = M_PI;
		else if (*c == 'S')
			dir = 3 * M_PI / 2;
		// *c = 1;
		return (dir);
	}
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	get_texture(game);
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->win)
		return (1);
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->img)
		return (1);
	game->addr = mlx_get_data_addr(game->img, &game->bpp, &game->line_len,
			&game->endian);
	return (0);
}

void	init_player(t_game *cube, t_player *player)
{
	int		x;
	int		y;
	double	d;

	ft_bzero(player, sizeof(t_player));
	d = -1.0f;
	y = -1;
	while (++y < cube->map->height)
	{
		x = -1;
		while (++x < cube->map->width)
		{
			d = get_player(&cube->map->map[y][x]);
			if (d != -1.0f)
				break;
		}
		if (d != -1.0f)
			break;
	}
	player->grid_x = x;
	player->grid_y = y;
	player->pos_x = x * TILE_SIZE + TILE_SIZE / 2;
	player->pos_y = y * TILE_SIZE + TILE_SIZE / 2;
	player->angle_dir = d;
	player->dir_x = cos(player->angle_dir);
	player->dir_y = sin(player->angle_dir);
	printf("x:%i, y:%i - px:%f, py:%f - angle:%f\n",
		x, y,
		player->pos_x,
		player->pos_y,
		d
	);
}
