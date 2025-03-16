/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:48:24 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/16 16:01:21 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * pixel_put - Sets a pixel color in the image buffer.
 * @game: Pointer to the game structure.
 * @x: X-coordinate of the pixel.
 * @y: Y-coordinate of the pixel.
 * @color: The color value to set (in RGBA format).
 *
 * Calculates the pixel's memory address and writes the color to it.
 */
void    pixel_put(t_game *game, int x, int y, int color)
{
    char    *dst;

    dst = game->addr + (y * game->line_len + x * (game->bpp / 8));
    *(unsigned int *)dst = color;
}

/**
 * normalize_angle - Keeps an angle within the range [0, 2π].
 * @angle: The angle in radians to be normalized.
 *
 * Ensures the given angle remains within the valid range by adjusting it:  
 * - If the angle is negative, it adds 2π.  
 * - If the angle exceeds 2π, it subtracts 2π.  
 * This keeps the angle bounded within one full rotation.
 *
 * Return: The normalized angle in the range [0, 2π].
 */
double  normalize_angle(double angle)
{
    if (angle < 0)
        angle += (2 * M_PI);
    if (angle > (2 * M_PI))
        angle -= (2 * M_PI);
    return (angle);
}

/**
 * wall_collision - Checks for collision with walls at the new player position.
 * @game: Pointer to the game structure.
 * @new_x: The new X-coordinate of the player.
 * @new_y: The new Y-coordinate of the player.
 *
 * Calculates the grid position based on the new coordinates and checks
 * whether the player would collide with a wall (represented by '1' on the map).
 * If the new position is out of bounds or a wall is encountered, returns 1.
 * Otherwise, returns 0.
 */
int wall_collision(t_game *game, double new_x, double new_y)
{
    int grid_x;
    int grid_y;

    grid_x = (int)(new_x / TILE_SIZE);
    grid_y = (int)(new_y / TILE_SIZE);
    if (grid_x < 0 || grid_x >= game->map->width || grid_y < 0
        || grid_y >= game->map->height)
        return (1);
    if (game->map->map[grid_y][grid_x] == '1')
        return (1);
    return (0);
}

int get_color(t_game *game, t_ray *ray)
{
    (void)game;
    ray->angle = normalize_angle(ray->angle);
    if (ray->side == 0)
    {
        if (ray->angle > M_PI / 2 && ray->angle < 3 * (M_PI / 2))
            return (3);
        else
            return (2);
    }
    else
    {
        if (ray->angle > 0 && ray->angle < M_PI)
            return (0);
        else
            return (1);
    }
}
