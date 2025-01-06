#include <cub3d.h>

void    pixel_put(t_game *game, int x, int y, int color)
{
    char    *dst;

    dst = game->addr + (y * game->line_len + x * (game->bpp / 8));
    *(unsigned int *)dst = color;
}

double  normalize_angle(double angle)
{
    if (angle < 0)
        angle += (2 * M_PI);
    if (angle > (2 * M_PI))
        angle -= (2 * M_PI);
    return (angle);
}

int wall_collision(t_game *game, double new_x, double new_y)
{
    int grid_x = (int)(new_x / TILE_SIZE);
    int grid_y = (int)(new_y / TILE_SIZE);

    if (
        grid_x < 0 ||
        grid_x >= game->map->width ||
        grid_y < 0 ||
        grid_y >= game->map->height
    )
        return (1);
    if (game->map->map[grid_y][grid_x] == '1')
        return (1);
    return (0);
}
