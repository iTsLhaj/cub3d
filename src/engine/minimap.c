#include <cub3d.h>

static void draw_square(t_game *game, int x, int y, int color)
{
    int i, j;
    int size = TILE_SIZE * MINIMAP_SCALE;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (!(x + j < 0 || x + j >= WIN_WIDTH || y + i < 0 || y + i >= WIN_HEIGHT))
                pixel_put(game, x + j, y + i, color);
        }
    }
}

void render_minimap(t_game *game)
{
    int square_size = TILE_SIZE * MINIMAP_SCALE;
    int view_range = 20; // view_range in tiles (radius around player)
    int player_tile_x = (int)(game->player->pos_x) / TILE_SIZE;
    int player_tile_y = (int)(game->player->pos_y) / TILE_SIZE;
    int start_i = (player_tile_y - view_range < 0) ? 0 : player_tile_y - view_range;
    int end_i   = (player_tile_y + view_range >= game->map->height) ? game->map->height - 1 : player_tile_y + view_range;
    int start_j = (player_tile_x - view_range < 0) ? 0 : player_tile_x - view_range;
    int end_j   = (player_tile_x + view_range >= game->map->width) ? game->map->width - 1 : player_tile_x + view_range;
    int i, j;
    int mx, my;
    int offset_x = (player_tile_x - start_j) * square_size;
    int offset_y = (player_tile_y - start_i) * square_size;
    int minimap_origin_x = 20; // fixed position in window
    int minimap_origin_y = 20; // fixed position in window

    // Draw only the visible range of the map
    for (i = start_i; i <= end_i; i++)
    {
        for (j = start_j; j <= end_j; j++)
        {
            mx = minimap_origin_x + (j - start_j) * square_size;
            my = minimap_origin_y + (i - start_i) * square_size;
            if (game->map->map[i][j] == '1')
                draw_square(game, mx, my, 0x690B22); // Wall (red)
            else
                draw_square(game, mx, my, 0xF1E3D3); // Floor (gray)
        }
    }

    // Draw player as a blue square centered in the minimap area
    mx = minimap_origin_x + offset_x;
    my = minimap_origin_y + offset_y;
    draw_square(game, mx - 2, my - 2, 0x000);
}
