/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:02:21 by hmouhib           #+#    #+#             */
/*   Updated: 2025/02/21 12:59:46 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static double	deg_to_rad(double deg)
{
	return deg * (M_PI / 180);
}

static void	rotate_player(t_game *game)
{
	if (game->player->ro == 1)
		game->player->angle_dir -= ROT_SPEED;
	else if (game->player->ro == -1)
		game->player->angle_dir += ROT_SPEED;
	game->player->angle_dir = normalize_angle(game->player->angle_dir);
	game->player->dir_x = cos(game->player->angle_dir);
	game->player->dir_y = sin(game->player->angle_dir);
}

static void	check_mv_flags(t_game *game, double *nx, double *ny)
{
	if (game->player->ud == 1)
	{
		*nx = game->player->pos_x + game->player->dir_x * MOVE_SPEED;
		*ny = game->player->pos_y + game->player->dir_y * MOVE_SPEED;
	}
	else if (game->player->ud == -1)
	{
		*nx = game->player->pos_x - game->player->dir_x * MOVE_SPEED;
		*ny = game->player->pos_y - game->player->dir_y * MOVE_SPEED;
	}
	else if (game->player->lr == -1)
	{
		*nx = game->player->pos_x - cos(game->player->angle_dir + deg_to_rad(90)) * MOVE_SPEED;
		*ny = game->player->pos_y - sin(game->player->angle_dir + deg_to_rad(90)) * MOVE_SPEED;
	}
	else if (game->player->lr == 1)
	{
		*nx = game->player->pos_x + cos(game->player->angle_dir + deg_to_rad(90)) * MOVE_SPEED;
		*ny = game->player->pos_y + sin(game->player->angle_dir + deg_to_rad(90)) * MOVE_SPEED;
	}

// 	if (game->player->lr == -1)
// 	{
// 		*nx = game->player->pos_x + game->player->dir_y * MOVE_SPEED;
// 		*ny = game->player->pos_y - game->player->dir_x * MOVE_SPEED;
// 	}
// 	else if (game->player->lr == 1)
// 	{
// 		*nx = game->player->pos_x - game->player->dir_y * MOVE_SPEED;
// 		*ny = game->player->pos_y + game->player->dir_x * MOVE_SPEED;
// 	}
}

void	update_player(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = 0;
	new_y = 0;
	check_mv_flags(
		game,
		&new_x,
		&new_y
		);
	if (!wall_collision(game, new_x, game->player->pos_y))
		game->player->pos_x = new_x;
	if (!wall_collision(game, game->player->pos_x, new_y))
		game->player->pos_y = new_y;
	rotate_player(game);
}
