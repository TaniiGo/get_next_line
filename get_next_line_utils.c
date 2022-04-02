/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keitanig <keitanig@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:27:06 by keitanig          #+#    #+#             */
/*   Updated: 2022/03/02 17:00:47 by keitanig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strdup(const char *str)
{
	char	*new;
	char	*n;

	new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!new)
		return (NULL);
	n = new;
	while (*str)
		*n++ = *str++;
	*n = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*new;
	char	*n;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * total_len + 1);
	if (!new)
		return (NULL);
	n = new;
	while (*s1)
		*n++ = *s1++;
	while (*s2)
		*n++ = *s2++;
	*n = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen <= start || len == 0)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
