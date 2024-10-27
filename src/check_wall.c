/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:10:29 by agaougao          #+#    #+#             */
/*   Updated: 2024/10/27 17:34:26 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int check_pos(char **map ,int i, int j)
{
	if(map[i + 1])
	{
		while(map[i + 1][j] && j > 0)
		{
			if(map[i + 1][j] != '1')
			{
				if(map[i + 1][j] ==  ' ')
				{
					if(map[i + 2][j] != '1')
					{
						return (1);
					}
				}
				else if(map[i + 1][j] == '0')
				{
					if(map[i][j] != '1')
						return (1);
				}
			}
			j--;
		}
	}
	return (0);
}
int check_wall_len(char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] != '1')
				j++;
			else
			{
				if(check_pos(map ,i,j))
					return (0);
				else
					break;
			}
		}
		i++;
	}
	return (1);
}
