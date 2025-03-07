/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:55:08 by agaougao          #+#    #+#             */
/*   Updated: 2025/02/26 04:53:21 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * check_inters - Checks for the closest intersection (horizontal or vertical).
 * @h_inter: Pointer to store the horizontal intersection distance.
 * @v_inter: Pointer to store the vertical intersection distance.
 * @ray: Pointer to the ray structure that holds ray-related data.
 * @game: Pointer to the game structure.
 *
 * Calculates the closest intersection distance
 * between horizontal and vertical rays, and updates
 * the ray's hit position, distance, and sets the side flag
 * for rendering purposes.
 */
static void	check_inters(
	float *h_inter,
	float *v_inter,
	t_ray *ray,
	t_game *game
)
{
	float	angle_normalized;

	angle_normalized = normalize_angle(ray->angle);
	*h_inter = get_hinter(game, angle_normalized);
	*v_inter = get_vinter(game, angle_normalized);
	if (*v_inter <= *h_inter)
	{
		ray->wall_dist = *v_inter;
		ray->wall_hit_x = game->vint_points.x;
		ray->wall_hit_y = game->vint_points.y;
	}
	else
	{
		ray->wall_dist = *h_inter;
		ray->wall_hit_x = game->hint_points.x;
		ray->wall_hit_y = game->hint_points.y;
		ray->side = 1;
	}
}

/**
 * cast_rays - Casts rays from the player's position to render the scene.
 * @game: Pointer to the game structure.
 *
 * Initializes ray angles based on the player's direction and FOV,
 * checks for intersections with walls (both horizontal and vertical),
 * and renders the corresponding wall strips.
 */
void	cast_rays(t_game *game)
{
	int		ray_index;
	float	v_inter;
	float	h_inter;
	t_ray	ray;

	ft_bzero(&ray, sizeof(t_ray));
	ray.angle = game->player->angle_dir - ((FOV_DEG * (M_PI / 180)) / 2);
	ray_index = 0;
	while (ray_index < WIN_WIDTH)
	{
		ray.side = 0;
		ray.index = ray_index;
		check_inters(&h_inter, &v_inter, &ray, game);
		render_wall(game, &ray);
		ray_index++;
		ray.angle += ((FOV_DEG * (M_PI / 180)) / WIN_WIDTH);
	}
}
