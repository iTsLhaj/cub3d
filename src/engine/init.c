#include <cub3d.h>

/** @todo recheck the compass ! */
static double	get_player(char *c)
{	
	double	dir;

	if (ft_strchr("NWSE", *c) == NULL)
		return (-1.0f);
	else
	{
		printf("[DEBUG]: player direction => %c\n", *c);
		if (*c == 'E')
			dir = 0;
		else if (*c == 'N')
			dir = M_PI / 2;
		else if (*c == 'W')
			dir = M_PI;
		else if (*c == 'S')
			dir = 3 * M_PI / 2;
		// *c = 1;
		return (dir);
	}
}

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(
		game->mlx,
		WIN_WIDTH,
		WIN_HEIGHT,
		WIN_TITLE
	);
	if (!game->win)
		return (1);
	game->img = mlx_new_image(
		game->mlx,
		WIN_WIDTH,
		WIN_HEIGHT
	);
	if (!game->img)
		return (1);
	game->addr = mlx_get_data_addr(
		game->img,
		&game->bpp,
		&game->line_len,
		&game->endian
	);
	return (0);
}

void	init_player(t_game *cube, t_player *player)
{
	int		x;
	int		y;
	double	d;

	ft_bzero(player, sizeof(t_player));
	x = 0;
	while (x < cube->map->height)
	{
		y = 0;
		while (y < cube->map->width)
		{
			d = get_player(&cube->map->map[x][y]);
			if (d != -1.0f)
				break ;
			y++;
		}
		if (d != -1.0f)
			break ;
		x++;
	}
	player->pos_y = x * TILE_SIZE + TILE_SIZE / 2;
	player->pos_x = y * TILE_SIZE + TILE_SIZE / 2;
	printf("[DEBUG]: player position => (%i:%f, %i:%f)[%f]\n",
		x, player->pos_x, y, player->pos_y, d);
	player->angle_dir = d;
	player->dir_x = cos(player->angle_dir);
	player->dir_y = sin(player->angle_dir);
}

int init_map(t_map *map)
{
    char *raw_map[] = {
		"11111111111111111111",
		"10000000000000000001",
		"10111111111111111001",
		"10100000000000001001",
		"10101111111011111001",
		"10100000000000000001",
		"10111000011111111001",
		"10000000000001000001",
		"10000010000000000001",
		"10111111111000011001",
		"10100000000000001001",
		"10101111111011111001",
		"10000000000000000001",
		"11111111111111111111",
		NULL
	};
    int height = 14;
    int width = 20;
	int i = -1;

    map->map = (char **)ft_calloc(height + 1, sizeof(char *));
    if (!map->map)
        return (1);
	while (++i < height)
	{
        map->map[i] = ft_strdup(raw_map[i]);
        if (!map->map[i])
            return (1);
    }
    map->width = width;
    map->height = height;
    return (0);
}
