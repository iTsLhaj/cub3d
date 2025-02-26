/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:31:40 by agaougao          #+#    #+#             */
/*   Updated: 2025/02/26 04:51:18 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * get_player - Returns the player's direction angle based on the map character.
 * @c: The map character representing the player's orientation.
 *
 * Returns the corresponding direction angle in radians:  
 * - 'E' -> 0  
 * - 'N' -> π/2  
 * - 'W' -> π  
 * - 'S' -> 3π/2  
 * Returns -1 if the character is not a valid player direction.
 */
static double	get_player(char c)
{
	double	dir;

	dir = -1.0f;
	if (ft_strchr("NWSE", c) == NULL)
		return (-1.0f);
	else
	{
		if (c == 'E')
			dir = 0;
		else if (c == 'N')
			dir = M_PI / 2;
		else if (c == 'W')
			dir = M_PI;
		else if (c == 'S')
			dir = 3 * M_PI / 2;
		return (dir);
	}
}

/**
 * init_mlx - Initializes the MLX library and creates the game window and image.
 * @game: Pointer to the game structure.
 *
 * Initializes the MLX instance, creates a new window, and loads textures.
 * Also creates a new image for rendering and retrieves the image's data 
 * address for pixel manipulation. Returns 1 on failure, 0 on success.
 */
int	init_mlx(t_game *game)
{
	game->mlx = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	get_texture(game);
	game->win = NULL;
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

/**
 * init_player - Initializes the player structure
 * and sets the initial position and direction.
 * @cube: Pointer to the game structure containing the map.
 * @player: Pointer to the player structure to be initialized.
 *
 * Finds the player's position on the map, sets the pixel position, 
 * and initializes direction vectors
 * based on the player's orientation in the map.
 */
void	init_player(t_game *cube, t_player *player)
{
	int		x;
	int		y;
	double	d;

	ft_bzero(player, sizeof(t_player));
	y = -1;
	while (++y < cube->map->height)
	{
		x = -1;
		while (++x < cube->map->width)
		{
			d = get_player(cube->map->map[y][x]);
			if (d != -1.0f)
				break ;
		}
		if (d != -1.0f)
			break ;
	}
	player->pos_x = (float)(x * TILE_SIZE) + (TILE_SIZE / 2.0f);
	player->pos_y = (float)(y * TILE_SIZE) + (TILE_SIZE / 2.0f);
	player->angle_dir = d;
	player->dir_x = cos(d);
	player->dir_y = sin(d);
}
