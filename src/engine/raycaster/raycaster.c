#include <stdio.h>
#include <cub3d.h>

void	cast_rays(t_game *game)
{
	int		ray_index;
	float	v_inter;
	float	h_inter;
	float	angle_normalized;
	t_ray	ray;

	ft_bzero(&ray, sizeof(t_ray));
	ray.angle = game->player->angle_dir - (FOV_RD / 2);
	ray_index = 0;
	while (ray_index < WIN_WIDTH)
	{
		ray.side = 0;
		ray.index = ray_index;
		angle_normalized = normalize_angle(ray.angle);

		h_inter = get_hinter(game, angle_normalized);
		v_inter = get_vinter(game, angle_normalized);

		if (v_inter <= h_inter)
			ray.wall_dist = v_inter;
		else
		{
			ray.wall_dist = h_inter;
			ray.side = 1;
		}

		render_wall(game, &ray);

		ray_index++;
		ray.angle += (FOV_RD / WIN_WIDTH);
	}
	// exit(0);
}