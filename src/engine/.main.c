#include <cub3d.h>
#include <X11/X.h>
#include <X11/Xutil.h>

static int	render_next(t_game *game)
{
	ft_bzero(
		game->addr,
		WIN_WIDTH * WIN_HEIGHT * (game->bpp / 8)
	);
	// update_player(game);
	// render_map(game);
	render_player(game);
	cast_rays(game);
	mlx_put_image_to_window(
		game->mlx,
		game->win,
		game->img,
		0,
		0
	);
	return (0);
}

int	main(void)
{
	t_game		game;
	t_player	player;
	t_map		map;

	if (init_mlx(&game))
		return (1);
	init_player(&player);
	if (init_map(&map))
		return (1);
	game.player = &player;
	game.map = &map;

	mlx_hook(game.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, key_release, &game);
	// mlx_hook(game.win, DestroyNotify, 0, end_game, &game);
	mlx_loop_hook(game.mlx, render_next, &game);
	mlx_loop(game.mlx);
	return (0);
}