/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:29:24 by agaougao          #+#    #+#             */
/*   Updated: 2025/02/18 19:51:45 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <X11/keysym.h>
#include <cub3d.h>

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
		ft_end(game);
	return (0);
}

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
