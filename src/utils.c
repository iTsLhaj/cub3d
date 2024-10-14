/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:08:44 by agaougao          #+#    #+#             */
/*   Updated: 2024/10/11 17:10:04 by agaougao         ###   ########.fr       */
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
