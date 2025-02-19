/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:36:38 by hmouhib           #+#    #+#             */
/*   Updated: 2025/02/19 17:01:00 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_end(t_game *game)
{
	int i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->texture_buffer[i]->img);
		free(game->texture_buffer[i]);
		i++;
	}

	i = 0;
	while (i < game->map->height)
		free(game->map->map[i++]);
	free(game->map->map);

	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);

	return (0);
}
