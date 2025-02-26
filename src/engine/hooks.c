/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:29:24 by agaougao          #+#    #+#             */
/*   Updated: 2025/02/26 02:58:50 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <X11/keysym.h>
#include <cub3d.h>

/**
 * key_press - Handles key press events and updates movement flags.
 * @keycode: The keycode of the pressed key.
 * @game: Pointer to the game structure.
 *
 * Sets the corresponding movement flag based on the pressed key:
 * - 'W' sets the 'ud' flag.
 * - 'S' sets the 'ud' flag.
 * - 'A' sets the 'lr' flag.
 * - 'D' sets the 'lr' flag.
 * - Left or Right arrow keys set the 'ro' flag (rotation).
 * - Escape key exits the game by ending the MLX loop.
 */
int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->player->ud = 1;
	else if (keycode == XK_s)
		game->player->ud = -1;
	else if (keycode == XK_a)
		game->player->lr = -1;
	else if (keycode == XK_d)
		game->player->lr = 1;
	else if (keycode == XK_Left)
		game->player->ro = 1;
	else if (keycode == XK_Right)
		game->player->ro = -1;
	else if (keycode == XK_Escape)
	{
		mlx_loop_end(game->mlx);
		return (1);
	}
	return (0);
}

/**
 * key_release - Handles key release events and updates movement flags.
 * @keycode: The keycode of the released key.
 * @game: Pointer to the game structure.
 *
 * Resets the corresponding movement flag based on the released key:
 * - 'W' or 'S' resets the 'ud' flag (up/down movement).
 * - 'A' or 'D' resets the 'lr' flag (left/right movement).
 * - Left or Right arrow keys reset the 'ro' flag (rotation).
 */
int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_s)
		game->player->ud = 0;
	else if (keycode == XK_a || keycode == XK_d)
		game->player->lr = 0;
	else if (keycode == XK_Left || keycode == XK_Right)
		game->player->ro = 0;
	return (0);
}
