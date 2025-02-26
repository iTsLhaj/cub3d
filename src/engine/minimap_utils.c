/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:18:51 by hmouhib           #+#    #+#             */
/*   Updated: 2025/02/26 02:18:52 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_tile(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TILE_SIZE * MINIMAP_SCALE)
	{
		j = -1;
		while (++j < TILE_SIZE * MINIMAP_SCALE)
			pixel_put(game, x + i, y + j, color);
	}
}

void	draw_minimap_tile(t_game *game, int i, int j)
{
	int	tile_x;
	int	tile_y;
	int	draw_x;
	int	draw_y;

	tile_x = (game->player->pos_x / TILE_SIZE) + j;
	tile_y = (game->player->pos_y / TILE_SIZE) + i;
	draw_x = 80 + (j * (TILE_SIZE * MINIMAP_SCALE));
	draw_y = 80 + (i * (TILE_SIZE * MINIMAP_SCALE));
	if (tile_x >= 0 && tile_x < game->map->width && tile_y >= 0
		&& tile_y < game->map->height)
	{
		if (game->map->map[tile_y][tile_x] == '1')
			draw_tile(game, draw_x, draw_y, MINIMAP_WALL_CLR);
		else
			draw_tile(game, draw_x, draw_y, MINIMAP_EMPTY_CLR);
	}
}
