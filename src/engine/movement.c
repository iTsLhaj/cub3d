/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:02:21 by hmouhib           #+#    #+#             */
/*   Updated: 2025/02/26 03:04:48 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * deg_to_rad - Converts degrees to radians.
 * @deg: The angle in degrees.
 *
 * Returns the angle in radians.
 */
static double	deg_to_rad(double deg)
{
	return (deg * (M_PI / 180));
}

/**
 * rotate_player - Rotates the player based on the rotation flag.
 * @game: Pointer to the game structure.
 *
 * Adjusts the player's direction angle and updates the direction vector.
 */
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

/**
 * check_mv_flags - Calculates the player's new position based on movement flags.
 * @game: Pointer to the game structure.
 * @nx: Pointer to store the calculated new X position.
 * @ny: Pointer to store the calculated new Y position.
 *
 * Updates the new position based on the flags:
 * - 'ud' (up/down) for forward/backward movement.
 * - 'lr' (left/right) for strafing left or right.
 */
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
		*nx = game->player->pos_x - cos(normalize_angle(
					game->player->angle_dir + deg_to_rad(90))) * MOVE_SPEED;
		*ny = game->player->pos_y - sin(normalize_angle(
					game->player->angle_dir + deg_to_rad(90))) * MOVE_SPEED;
	}
	else if (game->player->lr == 1)
	{
		*nx = game->player->pos_x + cos(normalize_angle(
					game->player->angle_dir + deg_to_rad(90))) * MOVE_SPEED;
		*ny = game->player->pos_y + sin(normalize_angle(
					game->player->angle_dir + deg_to_rad(90))) * MOVE_SPEED;
	}
}

/**
 * update_player - Updates the player's position based on movement flags and handles rotation.
 * @game: Pointer to the game structure.
 *
 * Performs movement and rotation updates:
 * - `check_mv_flags`: Updates the movement offsets for left/right/up/down.
 * - `wall_collision`: Checks if the player can move to the new position (handles sliding).
 * - `rotate_player`: Updates the player's rotation based on input.
 */
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
