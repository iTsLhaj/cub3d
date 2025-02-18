/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:51:41 by hmouhib           #+#    #+#             */
/*   Updated: 2025/02/18 19:21:15 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	draw_minimap_background(t_game *game, int bg_color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < MINIMAP_HEIGHT + (TILE_SIZE * MINIMAP_SCALE))
	{
		x = -1;
		while (++x < MINIMAP_WIDTH + (TILE_SIZE * MINIMAP_SCALE))
			pixel_put(game, x, y, bg_color);
	}
}

static void	draw_minimap_tiles(t_game *game, t_minimap_data *map_data)
{
	int	i;
	int	j;
	int	draw_x;
	int	draw_y;

	i = 0;
	while (1)
	{
		draw_y = i * (TILE_SIZE * MINIMAP_SCALE) - map_data->offset_y;
		if (draw_y >= MINIMAP_HEIGHT)
			break ;
		j = 0;
		while (1)
		{
			draw_x = j * (TILE_SIZE * MINIMAP_SCALE) - map_data->offset_x;
			if (draw_x >= MINIMAP_WIDTH)
				break ;
			draw_minimap_tile((int [4]){
				map_data->start_tile_x + j, map_data->start_tile_y + i,
				draw_x, draw_y}, game
				);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_player(t_game *game, t_minimap_data *map_data)
{
	int	i;
	int	j;
	int	player_size;

	player_size = (int)(TILE_SIZE * MINIMAP_SCALE / 2);
	i = -1;
	while (++i < player_size)
	{
		j = -1;
		while (++j < player_size)
			pixel_put(
				game,
				((int)((game->player->pos_x - map_data->view_top_left_x)
						* MINIMAP_SCALE) - player_size / 2) + j,
				((int)((game->player->pos_y - map_data->view_top_left_y)
						* MINIMAP_SCALE) - player_size / 2) + i,
				MINIMAP_WALL_PLAYER_CLR
				);
	}
}

void	render_minimap(t_game *game)
{
	t_minimap_data	mp_data;

	if (!game->player || !game->map)
		return ;
	draw_minimap_background(game, 0x000000);
	calculate_view(game, &mp_data);
	draw_minimap_tiles(game, &mp_data);
	draw_minimap_player(game, &mp_data);
}
