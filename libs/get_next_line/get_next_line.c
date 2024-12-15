/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:33:03 by hmouhib           #+#    #+#             */
/*   Updated: 2023/12/27 09:50:42 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_read_line(int fd, char *string)
{
	char	*chunk;
	ssize_t	rbytes;

	chunk = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	rbytes = 1;
	while (!gnl_strchr(string, '\n') && rbytes != 0)
	{
		rbytes = read(fd, chunk, BUFFER_SIZE);
		if (rbytes == -1)
		{
			free(chunk);
			return (NULL);
		}
		chunk[rbytes] = 0;
		string = gnl_strjoin(string, chunk);
	}
	free(chunk);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = gnl_read_line(fd, rest);
	if (!rest)
		return (NULL);
	line = gnl_get_line(rest);
	rest = gnl_get_rest(rest);
	return (line);
}
