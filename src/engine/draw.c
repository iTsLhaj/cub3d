#include <cub3d.h>
#include <stdio.h>

static void tile_put(t_game *game, int x, int y, int color)
{
    int tx;
    int ty;

    ty = 0;
    while (ty < TILE_SIZE)
    {
        tx = 0;
        while (tx < TILE_SIZE)
        {
            pixel_put(
                game,
                x + tx,
                y + ty,
                color
            );
            tx++;
        }
        ty++;
    }
}

static void draw_line(t_game *game, int line_size)
{
    int start_x = game->player->pos_x;
    int start_y = game->player->pos_y;
    double dir_x = game->player->dir_x;
    double dir_y = game->player->dir_y;
    int end_x = start_x + (int)(dir_x * line_size);
    int end_y = start_y + (int)(dir_y * line_size);
    int dx = abs(end_x - start_x);
    int dy = abs(end_y - start_y);
    int sx = (start_x < end_x) ? 1 : -1;
    int sy = (start_y < end_y) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        pixel_put(game, start_x, start_y, 0xFF0000);
        if (start_x == end_x && start_y == end_y)
            break;
        int err2 = err * 2;
        if (err2 > -dy)
        {
            err -= dy;
            start_x += sx;
        }
        if (err2 < dx)
        {
            err += dx;
            start_y += sy;
        }
    }
}

void    render_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->map[y][x] == '1')
                tile_put(game, x * TILE_SIZE, y * TILE_SIZE, 0x1A1A1D);
            else
                tile_put(game, x * TILE_SIZE, y * TILE_SIZE, 0xF8FAFC);
            x++;
        }
        y++;
    }
}

void render_player(t_game *game)
{
    int center_x = (int)(game->player->pos_x);
    int center_y = (int)(game->player->pos_y);
    int radius = 4;
    int color = 0xAF1740;

    int dy = -radius;
    while (dy <= radius)
    {
        int dx = -radius;
        while (dx <= radius)
        {
            if (dx * dx + dy * dy <= radius * radius)
                pixel_put(
                    game,
                    center_x + dx,
                    center_y + dy,
                    color
                );
            dx++;
        }
        dy++;
    }
    draw_line(game, 30);
}
