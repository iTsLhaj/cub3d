/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:18:59 by hmouhib           #+#    #+#             */
/*   Updated: 2025/02/26 04:28:07 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
