/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:48:24 by agaougao          #+#    #+#             */
/*   Updated: 2025/01/23 18:48:25 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->line_len + x * (game->bpp / 8));
	*(unsigned int *)dst = color;
}

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int	wall_collision(t_game *game, double new_x, double new_y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(new_x / TILE_SIZE);
	grid_y = (int)(new_y / TILE_SIZE);
	if (grid_x < 0 || grid_x >= game->map->width || grid_y < 0
		|| grid_y >= game->map->height)
		return (1);
	if (game->map->map[grid_y][grid_x] == '1')
		return (1);
	return (0);
}

int	get_color(t_game *game, t_ray *ray)
{
	(void)game;
	ray->angle = normalize_angle(ray->angle);
	if (ray->side == 0)
	{
		if (ray->angle > M_PI / 2 && ray->angle < 3 * (M_PI / 2))
			return (0);
		else
			return (1);
	}
	else
	{
		if (ray->angle > 0 && ray->angle < M_PI)
			return (2);
		else
			return (3);
	}
}
