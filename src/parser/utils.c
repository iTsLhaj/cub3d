/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:07:44 by agaougao          #+#    #+#             */
/*   Updated: 2025/02/20 15:32:03 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int count_commas(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == ',')
            count++;
        i++;
    }
    return (count);
}

int ft_check_for_space(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

int check_is_empty(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if ((line[i] >= 9 && line[i] <= 13) || line[i] != '\n')
            return (1);
        i++;
    }
    return (0);
}

int convert_color(t_game *cube)
{
    int red;
    int green;
    int blue;

    red = ft_atoi(cube->c[0]);
    green = ft_atoi(cube->c[1]);
    blue = ft_atoi(cube->c[2]);
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0
        || blue > 255)
        return (-1);
    return (red << 16 | green << 8 | blue);
}

void    ft_set_data(t_game *cube, int i, int j)
{
    t_map   *map;

    map = cube->map;
    if (map->map[i][j] == 'N' && map->map[i][j + 1] == 'O' && map->map[i][j
        + 2] == ' ')
        cube->no = ft_strtrim(&map->map[i][j + 2], " ");
    if (map->map[i][j] == 'W' && map->map[i][j + 1] == 'E' && map->map[i][j
        + 2] == ' ')
        cube->we = ft_strtrim(&map->map[i][j + 2], " ");
    if (map->map[i][j] == 'E' && map->map[i][j + 1] == 'A' && map->map[i][j
        + 2] == ' ')
        cube->ea = ft_strtrim(&map->map[i][j + 2], " ");
    if (map->map[i][j] == 'S' && map->map[i][j + 1] == 'O' && map->map[i][j
        + 2] == ' ')
        cube->so = ft_strtrim(&map->map[i][j + 2], " ");
    if (map->map[i][j] == 'F' && map->map[i][j + 1] == ' '
        && count_commas(map->map[i]) == 2)
        cube->f = ft_split(&map->map[i][j + 2], ',');
    if (map->map[i][j] == 'C' && map->map[i][j + 1] == ' '
        && count_commas(map->map[i]) == 2)
        cube->c = ft_split(&map->map[i][j + 2], ',');    
}
