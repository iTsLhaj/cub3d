/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftgc_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:29:52 by maomao            #+#    #+#             */
/*   Updated: 2024/11/30 04:55:52 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ftgc_strdup(const char *s, t_ncollector **collector)
{
	char	*str;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	str = (char *)n_malloc(collector, len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len);
	return (str);
}
