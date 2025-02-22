/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:36:38 by hmouhib           #+#    #+#             */
/*   Updated: 2025/02/22 15:40:32 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	free_mlx(t_game *game)
{
	if (game->mlx)
	{
		mlx_destroy_image(game->mlx, game->img);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	ft_end(t_game *game)
{
	int	i;

	if (game->texture_buffer[0] != NULL)
	{
		i = 0;
		while (i < 4)
		{
			mlx_destroy_image(game->mlx, game->texture_buffer[i]->img);
			free(game->texture_buffer[i]);
			i++;
		}
	}
	free_all(game->c);
	free(game->no);
	free_all(game->f);
	free(game->so);
	free(game->we);
	free(game->ea);
	free_all(game->map->map);
	free(game->map);
	free_mlx(game);
	return (0);
}
