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

static int	get_color(t_game *game, t_ray *ray)
{
	ray->angle = normalize_angle(ray->angle);
	if (ray->side == 0)
	{
		if (ray->angle > M_PI / 2 && ray->angle < 3 * (M_PI / 2))
			return (COLOR_PRIMARY);
		else
			return (COLOR_PRIMARY);
	}
	else
	{
		if (ray->angle > 0 && ray->angle < M_PI)
			return (COLOR_SECONDARY);
		else
			return (COLOR_SECONDARY);
	}
}

static void	draw_wall(t_game *game, t_ray *ray, int s_pix, int e_pix)
{
	int color;
	int	ray_i;

	ray_i = ray->index;
	color = get_color(game, ray);
	while (s_pix < e_pix)
		mlx_put_pixel_(game, ray_i, s_pix++, color);
}

static void	draw_floor_ceiling(t_game *game, t_ray *ray, int s_pix, int e_pix)
{
	int	i;

	i = e_pix;
	while (i < WIN_HEIGHT)
		mlx_put_pixel_(
			game,
			ray->index,
			i++,
			COLOR_FLOOR
		);
	i = 0;
	while (i < s_pix)
		mlx_put_pixel_(
			game,
			ray->index,
			i++,
			COLOR_CEILING
		);
}

void	render_wall(t_game *game, t_ray *ray)
{
	double	wall_height;
	double	e_pix;
	double	s_pix;

	ray->wall_dist *= cos(normalize_angle(ray->angle - game->player->angle_dir)); // fix the fisheye
	wall_height = (TILE_SIZE / ray->wall_dist) * ((WIN_WIDTH / 2) / tan(FOV_RD / 2)); // get the wall height
	e_pix = (WIN_HEIGHT / 2) + (wall_height / 2); // get the bottom pixel
	s_pix = (WIN_HEIGHT / 2) - (wall_height / 2); // get the top pixel
	if (e_pix > WIN_HEIGHT) // check the bottom pixel
		e_pix = WIN_HEIGHT;
	if (s_pix < 0) // check the top pixel
		s_pix = 0;
	draw_wall(game, ray, s_pix, e_pix); // draw the wall
	draw_floor_ceiling(game, ray, s_pix, e_pix); // draw the floor and the ceiling
}
