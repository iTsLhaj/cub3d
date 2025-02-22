/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:36:38 by hmouhib           #+#    #+#             */
/*   Updated: 2025/02/22 14:31:45 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void free_all(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}    
int ft_end(t_game *game)
{
    int i;

    i = 0;
    while (i < 4)
    {
        mlx_destroy_image(game->mlx, game->texture_buffer[i]->img);
        free(game->texture_buffer[i]);
        i++;
    }

    // i = 0;
    // while (i < game->map->height)
    //     free(game->map->map[i++]);
    // free(game->map->map);

    mlx_destroy_image(game->mlx, game->img);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    free_all(game->c);
    free(game->no);
    free_all(game->f);
    free(game->so);
    free(game->we);
    free(game->ea);
    free_all(game->map->map); // Free the 2D map array
    free(game->map); // Free the map structure
    // free(game);

    return (0);
}
