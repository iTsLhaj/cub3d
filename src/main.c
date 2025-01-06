#include <cub3d.h>
#include <X11/X.h>
#include <X11/Xutil.h>

static int  render_next(t_game *game)
{
    ft_bzero(
        game->addr,
        WIN_WIDTH * WIN_HEIGHT * (game->bpp / 8)
    );
    update_player(game);
    // render_map(game);
    // render_player(game);
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

int main(int ac, char **av)
{
    t_game      cube;
    t_player    player;
    
    if (check_arg(ac, av))
        return (ft_putstr_fd(
            "Error: invalid argument\n", 2), 1);
    if (check_map(&cube, av))
        return (ft_putstr_fd(
            "Error: invalid map\n", 2), 1);
    if (init_mlx(&cube))
        return (ft_putstr_fd(
            "Error: failed to initialize MLX\n", 2), 1);
    init_player(&cube, &player);
    cube.player = &player;
    mlx_hook(cube.win, KeyPress, KeyPressMask, key_press, &cube);
    mlx_hook(cube.win, KeyRelease, KeyReleaseMask, key_release, &cube);
    mlx_loop_hook(cube.mlx, render_next, &cube);
    mlx_loop(cube.mlx);
    return (0);
}