/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmouhib <hmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:32:56 by hmouhib           #+#    #+#             */
/*   Updated: 2023/12/22 18:06:17 by hmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(char *s)
{
	size_t	l;

	l = 0;
	if (!s)
		return (l);
	while (s[l])
		l++;
	return (l);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (&s[i]);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}

char	*gnl_strjoin(char *chunk1, char *chunk2)
{
	size_t	i;
	size_t	j;
	char	*buffer;

	if (!chunk1)
	{
		chunk1 = (char *)malloc(1 * sizeof(char));
		*chunk1 = '\0';
	}
	if (!chunk1 || !chunk2)
		return (NULL);
	buffer = (char *)malloc((gnl_strlen(chunk1) + gnl_strlen(chunk2) + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (chunk1[i])
		buffer[j++] = chunk1[i++];
	i = 0;
	while (chunk2[i])
		buffer[j++] = chunk2[i++];
	buffer[j] = 0;
	free(chunk1);
	return (buffer);
}

char	*gnl_get_line(char *buffer)
{
	char	*line_;
	size_t	n;

	n = 0;
	if (!buffer[n])
		return (NULL);
	while (buffer[n] && buffer[n] != '\n')
		n++;
	line_ = (char *)malloc((n + 2) * sizeof(char));
	if (!line_)
		return (NULL);
	n = 0;
	while (buffer[n] && buffer[n] != '\n')
	{
		line_[n] = buffer[n];
		n++;
	}
	if (buffer[n] == '\n')
		line_[n++] = '\n';
	line_[n] = 0;
	return (line_);
}

char	*gnl_get_rest(char *buffer)
{
	char	*new_chunk;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	size = gnl_strlen(&buffer[i]);
	new_chunk = (char *)malloc(size + 1);
	j = 0;
	while (buffer[i])
		new_chunk[j++] = buffer[i++];
	new_chunk[j] = 0;
	free(buffer);
	return (new_chunk);
}
