/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:18:59 by hmouhib           #+#    #+#             */
/*   Updated: 2025/02/26 04:40:08 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * draw_background - Fills the minimap background with a solid color.
 * @game: Pointer to the game structure.
 *
 * Iterates over the minimap dimensions and colors each pixel black
 * to create a background for the minimap.
 */
void	draw_background(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (++j < MINIMAP_HEIGHT)
	{
		i = -1;
		while (++i < MINIMAP_WIDTH)
			pixel_put(game, j, i, 0x000000);
	}
}

/**
 * draw_minimap_tiles - Renders the minimap tiles around the player.
 * @game: Pointer to the game structure.
 *
 * Iterates through a range of tiles based on minimap size and
 * calls draw_minimap_tile to render each tile.
 * 
 * 			[-2]
 * 			[-1]
 * 	[-2][-1][ 0][ 1][ 2]
 * 			[ 1]
 * 			[ 2]
 * 
 */
void	draw_minimap_tiles(t_game *game)
{
	int	i;
	int	j;

	i = -game->mp_data.size - 1;
	while (++i <= game->mp_data.size)
	{
		j = -game->mp_data.size - 1;
		while (++j <= game->mp_data.size)
			draw_minimap_tile(game, i, j);
	}
}

/**
 * draw_minimap_player - Draws the player on the minimap.
 * @game: Pointer to the game structure.
 *
 * Renders a small square representing the player at the minimap's center,
 * adjusted by offsets to ensure smooth movement within its NxN tile.
 */
void	draw_minimap_player(t_game *game)
{
	int				size;
	int				i;
	int				j;
	t_minimap_data	mp;

	mp = game->mp_data;
	size = TILE_SIZE * MINIMAP_SCALE / 2;
	i = -size / 2;
	while (i < size / 2)
	{
		j = -size / 2;
		while (j < size / 2)
		{
			pixel_put(game, mp.center_x + mp.offset_x + i, mp.center_y
				+ mp.offset_y + j, MINIMAP_PLAYER_CLR);
			j++;
		}
		i++;
	}
}

/**
 * render_minimap - Renders the minimap.
 * @game: Pointer to the game structure.
 *
 * Sets up minimap properties like size, padding, center position,
 * and player offsets for smooth movement. Calls drawing functions to
 * render the background, tiles, and player.
 */
void	render_minimap(t_game *game)
{
	t_minimap_data	mp;
	int				x;

	mp.size = 5;
	mp.padding = (TILE_SIZE * MINIMAP_SCALE) * mp.size;
	x = mp.padding - (2 * (TILE_SIZE * MINIMAP_SCALE));
	mp.center_x = x + (2 * (TILE_SIZE * MINIMAP_SCALE));
	mp.center_y = x + (2 * (TILE_SIZE * MINIMAP_SCALE));
	mp.offset_x = (((int)game->player->pos_x % TILE_SIZE) * MINIMAP_SCALE) / 2;
	mp.offset_y = (((int)game->player->pos_y % TILE_SIZE) * MINIMAP_SCALE) / 2;
	game->mp_data = mp;
	draw_background(game);
	draw_minimap_tiles(game);
	draw_minimap_player(game);
}
