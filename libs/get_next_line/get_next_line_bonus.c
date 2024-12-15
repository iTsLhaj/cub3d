/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:32:49 by hmouhib           #+#    #+#             */
/*   Updated: 2023/12/22 20:13:52 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*rest[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = gnl_read_line(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = gnl_get_line(rest[fd]);
	rest[fd] = gnl_get_rest(rest[fd]);
	return (line);
}
