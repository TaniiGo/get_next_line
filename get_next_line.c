/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:36:46 by keitanig          #+#    #+#             */
/*   Updated: 2022/03/03 21:52:20 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*join_remainder_and_buffer(char *remainder, char *buffer)
{
	char	*tmp;

	tmp = remainder;
	remainder = ft_strjoin(remainder, buffer);
	free(tmp);
	tmp = NULL;
	return (remainder);
}

static char	*get_line_to_lf(char *remainder)
{
	char		*line;
	size_t		len;

	line = NULL;
	len = 0;
	if (!remainder[len])
		return (line);
	while (remainder[len] && remainder[len] != '\n')
		len++;
	line = (char *)malloc(sizeof(char) * len + 2);
	len = 0;
	while (remainder[len] && remainder[len] != '\n')
	{
		line[len] = remainder[len];
		len++;
	}
	line[len] = remainder[len];
	line[len + 1] = '\0';
	return (line);
}

static char	*find_linefeed(int fd, char *remainder, char *buffer)
{
	ssize_t	read_value;

	if (ft_strchr(remainder, '\n'))
		return (remainder);
	read_value = read(fd, buffer, BUFFER_SIZE);
	while (read_value != -1)
	{
		if (!read_value)
			return (remainder);
		buffer[read_value] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		remainder = join_remainder_and_buffer(remainder, buffer);
		if (ft_strchr(remainder, '\n'))
			return (remainder);
		read_value = read(fd, buffer, BUFFER_SIZE);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*buffer;
	char		*tmp;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	remainder = find_linefeed(fd, remainder, buffer);
	free(buffer);
	if (!remainder)
		return (NULL);
	line = get_line_to_lf(remainder);
	len = ft_strlen(line);
	tmp = remainder;
	remainder = ft_substr(remainder, len, ft_strlen(remainder) - len);
	free(tmp);
	return (line);
}
