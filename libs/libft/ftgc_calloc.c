/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftgc_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 00:29:52 by maomao            #+#    #+#             */
/*   Updated: 2024/11/30 04:55:44 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ftgc_calloc(size_t s, size_t size, t_ncollector **collector)
{
	void	*ptr;

	ptr = n_malloc(collector, s * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, s * size);
	return (ptr);
}
