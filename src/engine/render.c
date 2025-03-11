/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:40:11 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/11 12:40:55 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	mlx_put_pixel_(t_game *game, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= WIN_WIDTH)
		return ;
	else if (y < 0)
		return ;
	else if (y >= WIN_HEIGHT)
		return ;
	pixel_put(game, x, y, color);
}

int	get_pixel_image(t_img *img, int x, int y)
{
	char	*dst;

	if (x < 0)
		return (0);
	else if (x >= WIN_WIDTH)
		return (0);
	else if (y < 0)
		return (0);
	else if (y >= WIN_HEIGHT)
		return (0);
	dst = (img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8)));
	return (*(unsigned int *)dst);
}

static void	draw_wall(t_game *game, t_ray *ray, int s_pix, int e_pix)
{
	int	color;
	int	x;
	int	y;

	if (ray->side)
	{
		x = (int)ray->wall_hit_x % 64;
	}
	else
		x = (int)ray->wall_hit_y % 64;
	while (s_pix < e_pix)
	{
		y = (s_pix - ((WIN_HEIGHT - game->w_height) / 2)) * (64
				/ game->w_height);
		color = get_pixel_image(game->texture_buffer[get_color(game, ray)], x,
				y);
		mlx_put_pixel_(game, ray->index, s_pix, color);
		s_pix++;
	}
}

static void	draw_floor_ceiling(t_game *game, t_ray *ray, int s_pix, int e_pix)
{
	int	i;

	i = e_pix;
	while (i < WIN_HEIGHT)
		mlx_put_pixel_(game, ray->index, i++, game->floor_color);
	i = 0;
	while (i < s_pix)
		mlx_put_pixel_(game, ray->index, i++, game->ceiling_color);
}

/**
 * @brief This function calculates the wall strip height and draws it on screen!
 * @details
 * 
 *    So our player looks at the wall:
 *    
 *          |\
 *          | \ 
 *    wall  |__(FOV) [PLAYER]
 *          | /
 *          |/ e.g: here the ray hits!
 *    
 *    + ray->wall_dist: Distance to the wall (ray->wall_hit).
 *    + pp_dist: Distance to projection plane, calculated as:
 *        pp_dist = (WIN_WIDTH/2) / tan((FOV_DEG * (M_PI / 180)) / 2).
 *    
 *    Projection plane view:
 * 
 *              projection plane!
 *             /
 *          |\ /
 *          | |\
 *          | | \
 *    wall->| |  (*> <- [player] (cam)
 *          | | /
 *          | |/
 *          |/
 *    
 *    Notice two similar triangles (Thales Theorem):
 * 
 *          |\
 *          | \
 *          |  \      |\
 *          |   \     | \
 *        A |    >  C |  >
 *          |   /     | / D
 *          |  / B    |/
 *          | /
 *          |/
 *    
 *    By Thales Theorem (A/B = C/D):
 *    - A: TILE_SIZE (real wall height),
 *    - B: ray->wall_dist (distance to wall),
 *    - C: pp_dist (distance to projection plane),
 *    - D: wall_height (projected wall height on screen).
 *    
 *    So: D = (A / B) * C
 *    -> wall_height = (TILE_SIZE / ray->wall_dist) * pp_dist.
 *    This gives us the walls height in pixels, then we draw it!
 * 
 */
void	render_wall(t_game *game, t_ray *ray)
{
	double	pp_dist;
	double	wall_height;
	double	e_pix;
	double	s_pix;

	ray->wall_dist *= cos(normalize_angle(ray->angle
				- game->player->angle_dir));
	pp_dist = ((WIN_WIDTH / 2) / tan((FOV_DEG * (M_PI / 180)) / 2));
	wall_height = (TILE_SIZE / ray->wall_dist) * pp_dist;
	e_pix = (WIN_HEIGHT / 2) + (wall_height / 2);
	s_pix = (WIN_HEIGHT / 2) - (wall_height / 2);
	if (e_pix > WIN_HEIGHT)
		e_pix = WIN_HEIGHT;
	if (s_pix < 0)
		s_pix = 0;
	game->w_height = wall_height;
	draw_wall(game, ray, s_pix, e_pix);
	draw_floor_ceiling(game, ray, s_pix, e_pix);
}
