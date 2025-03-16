/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:36:38 by hmouhib           #+#    #+#             */
/*   Updated: 2025/03/14 13:39:37 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * free_mlx - Frees the resources allocated by mlx.
 * @game: Pointer to the game structure.
 *
 * Destroys the mlx image, window, and display, and frees the mlx pointer.
 */
static void free_mlx(t_game *game)
{
    if (game->mlx)
    {
        if (game->img)
            mlx_destroy_image(game->mlx, game->img);
        if (game->win)
            mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
}

/**
 * free_all - Frees a 2D array of strings (char**).
 * @str: Pointer to the 2D array to be freed.
 *
 * Iterates through the array and frees each string,
    then frees the array itself.
 */
void    free_all(char **str)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

/**
 * ft_end - Frees all allocated memory for the game and terminates the program.
 * @game: Pointer to the game structure.
 *
 * Frees the texture buffers, the ceiling and floor color arrays
 * the texture paths, the game map, and the map structure.
 * Also calls `free_mlx` to clean up the MLX library resources.
 * Always returns 0.
 */
int ft_end(t_game *game)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (game->texture_buffer[i] != NULL)
        {
            mlx_destroy_image(game->mlx, game->texture_buffer[i]->img);
            free(game->texture_buffer[i]);
        }
        i++;
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
