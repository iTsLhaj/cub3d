/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:55:11 by agaougao          #+#    #+#             */
/*   Updated: 2025/02/26 04:24:14 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * touch - Checks if a given position collides with a wall.
 * @game: Pointer to the game structure.
 * @x: X-coordinate in the game world.
 * @y: Y-coordinate in the game world.
 *
 * Determines whether the given (x, y) position is within bounds and not a wall.
 * Returns 1 if the position is free, 0 if it collides with a wall or is out of bounds.
 */
int	touch(t_game *game, double x, double y)
{
	char	**grid;
	int		grid_x;
	int		grid_y;

	grid = game->map->map;
	if (x < 0 || y < 0 || x >= game->map->width * TILE_SIZE
		|| y >= game->map->height * TILE_SIZE)
		return (0);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	if ((grid_y >= game->map->height || grid_x >= game->map->width))
		return (0);
	if (grid[grid_y] && grid_x < (int)ft_strlen(grid[grid_y]))
	{
		if (grid[grid_y][grid_x] == '1')
			return (0);
	}
	return (1);
}

/**
 * inter_check - Adjusts the intercept and step based on the ray angle.
 * @angle: Ray angle in radians.
 * @inter: Pointer to the initial intercept coordinate.
 * @step: Pointer to the step size.
 * @dir: 'h' for horizontal, 'v' for vertical.
 *
 * Ensures the ray starts at the correct tile boundary and moves in the right direction.
 * Returns 1 if no adjustment is needed, -1 if the intercept is shifted by TILE_SIZE.
 */
int	inter_check(float angle, float *inter, float *step, char dir)
{
	if (dir == 'h')
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

/**
 * unit_circle - Determines if the step should be reversed based on angle.
 * @angle: The ray angle in radians.
 * @axis: 'x' or 'y' to specify the axis.
 *
 * For the x-axis, returns 1 if the angle is between 0 and π.
 * For the y-axis, returns 1 if the angle is between π/2 and 3π/2.
 * Returns 0 otherwise.
 */
int	unit_circle(float angle, char axis)
{
	if (axis == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (axis == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}
