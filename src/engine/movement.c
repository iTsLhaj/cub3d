#include <cub3d.h>

static void	rotate_player(t_game *game)
{
	if (game->player->ro == 1)
		game->player->angle_dir -= ROT_SPEED;
	else if (game->player->ro == -1)
		game->player->angle_dir += ROT_SPEED;
	
	game->player->angle_dir = normalize_angle(game->player->angle_dir);
	game->player->dir_x = cos(game->player->angle_dir);
	game->player->dir_y = sin(game->player->angle_dir);
}

void	update_player(t_game *game)
{
	double	new_x;
	double	new_y;

	if (game->player->ud == 1)
	{
		new_x = game->player->pos_x + game->player->dir_x * MOVE_SPEED;
		new_y = game->player->pos_y + game->player->dir_y * MOVE_SPEED;
	}
	else if (game->player->ud == -1)
	{
		new_x = game->player->pos_x - game->player->dir_x * MOVE_SPEED;
		new_y = game->player->pos_y - game->player->dir_y * MOVE_SPEED;
	}
	if (game->player->lr == -1)
	{
		new_x = game->player->pos_x + game->player->dir_y * MOVE_SPEED;
		new_y = game->player->pos_y - game->player->dir_x * MOVE_SPEED;
	}
	else if (game->player->lr == 1)
	{
		new_x = game->player->pos_x - game->player->dir_y * MOVE_SPEED;
		new_y = game->player->pos_y + game->player->dir_x * MOVE_SPEED;
	}
	if (!wall_collision(game, new_x, new_y))
	{
		game->player->pos_x = new_x;
		game->player->pos_y = new_y;
	}
	rotate_player(game);
}
