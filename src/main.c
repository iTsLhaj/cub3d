/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:49:25 by agaougao          #+#    #+#             */
/*   Updated: 2025/01/23 18:53:58 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <X11/Xutil.h>
#include <cub3d.h>

static int	render_next(t_game *game)
{
	ft_bzero(game->addr, WIN_WIDTH * WIN_HEIGHT * (game->bpp / 8));
	update_player(game);
	cast_rays(game);
	render_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

static void	display_map_grid(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map->height)
	{
		x = -1;
		while (++x < game->map->width)
			printf("%c", game->map->map[y][x]);
		printf("\n");
	}
}

int	main(int ac, char **av)
{
	t_player	player;
	t_game		cube;

	if (check_arg(ac, av))
		return (ft_putstr_fd("Error: invalid argument\n", 2), 1);
	if (check_map(&cube, av))
		return (ft_putstr_fd("Error: invalid map\n", 2), 1);
	if (init_mlx(&cube))
		return (ft_putstr_fd("Error: failed to initialize MLX\n", 2), 1);
	init_player(&cube, &player);
	cube.player = &player;
	display_map_grid(&cube);
	mlx_hook(cube.win, KeyPress, KeyPressMask, key_press, &cube);
	mlx_hook(cube.win, KeyRelease, KeyReleaseMask, key_release, &cube);
	mlx_loop_hook(cube.mlx, render_next, &cube);
	mlx_loop(cube.mlx);
	return (0);
}
