#include <cub3d.h>

# define MINIMAP_WALL_BLOCK_CLR  0x690B22
# define MINIMAP_WALL_FLOOR_CLR  0xF7F7F7
# define MINIMAP_WALL_PLAYER_CLR 0x0000FF

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

static void draw_minimap_background(t_game *game, int bg_color)
{
    int x, y;
    for (y = 0; y < MINIMAP_HEIGHT + (TILE_SIZE * MINIMAP_SCALE); y++)
    {
        for (x = 0; x < MINIMAP_WIDTH + (TILE_SIZE * MINIMAP_SCALE); x++)
        {
            pixel_put(game, x, y, bg_color);
        }
    }
}

void render_minimap(t_game *game)
{
    int i, j;
    float mini_tile_size = TILE_SIZE * MINIMAP_SCALE;
    int minimap_width = MINIMAP_WIDTH;
    int minimap_height = MINIMAP_HEIGHT;

    if (!game->player || !game->map)
        return;

    draw_minimap_background(game, 0x000000);

    // Determine the world area (in pixels) that maps to the minimap.
    float view_world_width = minimap_width / MINIMAP_SCALE;
    float view_world_height = minimap_height / MINIMAP_SCALE;

    // Top-left of the world view, centered on the player.
    float view_top_left_x = game->player->pos_x - view_world_width / 2;
    float view_top_left_y = game->player->pos_y - view_world_height / 2;

    // Determine starting tile and offset within that tile.
    int start_tile_x = floor(view_top_left_x / TILE_SIZE);
    int start_tile_y = floor(view_top_left_y / TILE_SIZE);
    float offset_x = (view_top_left_x - start_tile_x * TILE_SIZE) * MINIMAP_SCALE;
    float offset_y = (view_top_left_y - start_tile_y * TILE_SIZE) * MINIMAP_SCALE;

    // Draw tiles until we fill the minimap.
    for (i = 0; ; i++)
    {
        int draw_y = i * mini_tile_size - offset_y;
        if (draw_y >= minimap_height)
            break;
        for (j = 0; ; j++)
        {
            int draw_x = j * mini_tile_size - offset_x;
            if (draw_x >= minimap_width)
                break;
            int tile_x = start_tile_x + j;
            int tile_y = start_tile_y + i;
            if (tile_x >= 0 && tile_x < game->map->width &&
                tile_y >= 0 && tile_y < game->map->height)
            {
                char tile = game->map->map[tile_y][tile_x];
                int color = (tile == '1') ? MINIMAP_WALL_BLOCK_CLR : MINIMAP_WALL_FLOOR_CLR;
                draw_square(game, draw_x, draw_y, color);
            }
        }
    }

    // Draw player as a small square at the appropriate minimap position.
    int player_mini_x = (game->player->pos_x - view_top_left_x) * MINIMAP_SCALE;
    int player_mini_y = (game->player->pos_y - view_top_left_y) * MINIMAP_SCALE;
    draw_square(game, player_mini_x, player_mini_y, MINIMAP_WALL_PLAYER_CLR);
}

