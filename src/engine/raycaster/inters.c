/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:55:02 by agaougao          #+#    #+#             */
/*   Updated: 2025/02/26 04:07:47 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * get_hinter - Computes the horizontal intersection of a ray.
 * @game: Pointer to the game structure.
 * @angle: The ray's angle in radians.
 *
 * Determines the nearest horizontal intersection point of the ray by stepping
 * along the grid. Uses trigonometric calculations to find the step size and
 * adjusts the stepping direction based on the ray's angle. The function
 * returns the computed distance from the player's position to the hit point.
 */
float	get_hinter(t_game *game, float angle)
{
	float	hx;
	float	hy;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angle);
	hy = floor(game->player->pos_y / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angle, &hy, &y_step, 'h');
	hx = game->player->pos_x + (hy - game->player->pos_y) / tan(angle);
	if ((unit_circle(angle, 'y') && x_step > 0) || (!unit_circle(angle, 'y')
			&& x_step < 0))
		x_step *= -1;
	while (touch(game, hx, hy - pixel))
	{
		hx += x_step;
		hy += y_step;
	}
	game->hint_points.x = hx;
	game->hint_points.y = hy;
	return (sqrt(pow(hx - game->player->pos_x, 2) + pow(hy
				- game->player->pos_y, 2)));
}

/**
 * get_vinter - Computes the vertical intersection of a ray.
 * @game: Pointer to the game structure.
 * @angle: The ray's angle in radians.
 *
 * Determines the nearest vertical intersection point of the ray by stepping
 * along the grid. Uses trigonometric calculations to find the step size and
 * adjusts the stepping direction based on the ray's angle. The function
 * returns the computed distance from the player's position to the hit point.
 */
float	get_vinter(t_game *game, float angle)
{
	float	vx;
	float	vy;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angle);
	vx = floor(game->player->pos_x / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angle, &vx, &x_step, 'v');
	vy = game->player->pos_y + (vx - game->player->pos_x) * tan(angle);
	if ((unit_circle(angle, 'x') && y_step < 0) || (!unit_circle(angle, 'x')
			&& y_step > 0))
		y_step *= -1;
	while (touch(game, vx - pixel, vy))
	{
		vx += x_step;
		vy += y_step;
	}
	game->vint_points.x = vx;
	game->vint_points.y = vy;
	return (sqrt(pow(vx - game->player->pos_x, 2) + pow(vy
				- game->player->pos_y, 2)));
}
