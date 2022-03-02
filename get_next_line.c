/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:36:46 by keitanig          #+#    #+#             */
/*   Updated: 2022/03/02 18:51:39 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_remainder_and_buffer(char *remainder, char *buffer)
{
	char	*tmp;

	tmp = remainder;
	remainder = ft_strjoin(remainder, buffer);
	free(tmp);
	tmp = NULL;
	return (remainder);
}

static char	*adjust_remainder(char *line)
{
	char			*ret;
	unsigned int	i;

	ret = NULL;
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (ret);
	if (line[i + 1])
		ret = ft_substr(line, i + 1, ft_strlen(line) - (i + 1));
	line[i + 1] = '\0';
	return (ret);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = find_linefeed(fd, remainder, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	remainder = adjust_remainder(line);
	return (line);
}
