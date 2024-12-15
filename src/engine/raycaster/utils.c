#include <stdio.h>
#include <cub3d.h>

int	touch(t_game *game, double x, double y)
{
	char	**grid;
	int		grid_x;
	int		grid_y;

	grid = game->map->map;
	if (x < 0 || y < 0 || x >= game->map->width * TILE_SIZE || y >= game->map->height * TILE_SIZE)
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
