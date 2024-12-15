/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftgc_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:29:52 by maomao            #+#    #+#             */
/*   Updated: 2024/11/30 04:56:51 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ftgc_strmapi(char const *s, char (*f)(unsigned int, char),
		t_ncollector **collector)
{
	unsigned int	i;
	size_t			len;
	char			*string;

	len = ft_strlen(s) + 1;
	string = (char *)n_malloc(collector, len);
	if (!string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = 0;
	return (string);
}
