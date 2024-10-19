/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:00:45 by agaougao          #+#    #+#             */
/*   Updated: 2024/10/16 17:04:44 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<cub3d.h>

int check_map_wall(t_cub3d *cube)
{
	int i;
	int j;
	char **map_cpy;

	i = 0;
	while(map[i])
	{
		j = 0;
		if(check_is_empty(map[i]) == 0)
		{
			while(map[i][j])
			{
				if()
				j++;
			}
		}
	}
}
