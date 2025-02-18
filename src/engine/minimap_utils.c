/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:58:39 by hmouhib           #+#    #+#             */
/*   Updated: 2025/02/18 19:00:18 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_square(t_game *game, int x, int y, int color)
{
	int	size;
	int	i;
	int	j;

	size = TILE_SIZE * MINIMAP_SCALE;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (!(x + j < 0 || x + j >= WIN_WIDTH
					|| y + i < 0 || y + i >= WIN_HEIGHT))
				pixel_put(game, x + j, y + i, color);
		}
	}
}

void	draw_minimap_tile(int *points, t_game *game)
{
	int	t_x;
	int	t_y;
	int	d_x;
	int	d_y;

	t_x = points[0];
	t_y = points[1];
	d_x = points[2];
	d_y = points[3];
	if (t_x >= 0 && t_x < game->map->width && t_y >= 0
		&& t_y < game->map->height)
	{
		if (game->map->map[t_y][t_x] == '1')
			draw_square(game, d_x, d_y, MINIMAP_WALL_BLOCK_CLR);
		else
			draw_square(game, d_x, d_y, MINIMAP_WALL_FLOOR_CLR);
	}
}

void	calculate_view(t_game *game, t_minimap_data *map_data)
{
	float	view_world_width;
	float	view_world_height;

	view_world_width = MINIMAP_WIDTH / MINIMAP_SCALE;
	view_world_height = MINIMAP_HEIGHT / MINIMAP_SCALE;
	map_data->view_top_left_x = game->player->pos_x - view_world_width / 2;
	map_data->view_top_left_y = game->player->pos_y - view_world_height / 2;
	map_data->start_tile_x = floor(map_data->view_top_left_x / TILE_SIZE);
	map_data->start_tile_y = floor(map_data->view_top_left_y / TILE_SIZE);
	map_data->offset_x = (map_data->view_top_left_x - map_data->start_tile_x
			* TILE_SIZE) * MINIMAP_SCALE;
	map_data->offset_y = (map_data->view_top_left_y - map_data->start_tile_y
			* TILE_SIZE) * MINIMAP_SCALE;
}
