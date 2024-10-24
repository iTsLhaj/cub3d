/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:08:44 by agaougao          #+#    #+#             */
/*   Updated: 2024/10/16 16:35:43 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<cub3d.h>

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
	return(count);
}

int	ft_check_for_space(char *str)
{
	int	i;

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
	while(line[i])
	{
		if((line[i] >= 9 && line[i] <= 13) || line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
