/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:18:51 by hmouhib           #+#    #+#             */
/*   Updated: 2025/02/26 04:52:21 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * draw_tile - Draws a scaled tile on the minimap.
 * @game: Pointer to the game structure.
 * @x: X-coordinate of the tile on the minimap.
 * @y: Y-coordinate of the tile on the minimap.
 * @color: Color of the tile.
 *
 * Fills a rectangular area representing a tile, scaled by MINIMAP_SCALE,
 * by setting pixels using pixel_put.
 */
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

/**
 * draw_minimap_tile - Draws walls and empty tiles on the minimap.
 * @game: Pointer to the game structure.
 * @i: Row index relative to the player.
 * @j: Column index relative to the player.
 *
 * Determines the corresponding map tile and draws it with the appropriate color.
 *  - Walls are drawn with MINIMAP_WALL_CLR.
 *  - Empty spaces with MINIMAP_EMPTY_CLR.
 * 
 * NOTE:
 * when drawing minimap tiles above the background,
 * this padding give a border like look to the minimap!
 */
void	draw_minimap_tile(t_game *game, int i, int j)
{
	int	tile_x;
	int	tile_y;
	int	draw_x;
	int	draw_y;

	tile_x = (game->player->pos_x / TILE_SIZE) + j;
	tile_y = (game->player->pos_y / TILE_SIZE) + i;
	draw_x = game->mp_data.padding + (j * (TILE_SIZE * MINIMAP_SCALE));
	draw_y = game->mp_data.padding + (i * (TILE_SIZE * MINIMAP_SCALE));
	if (tile_x >= 0 && tile_x < game->map->width && tile_y >= 0
		&& tile_y < game->map->height)
	{
		if (game->map->map[tile_y][tile_x] == '1')
			draw_tile(game, draw_x, draw_y, MINIMAP_WALL_CLR);
		else
			draw_tile(game, draw_x, draw_y, MINIMAP_EMPTY_CLR);
	}
}
