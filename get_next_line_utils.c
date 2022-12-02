/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:22:39 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/01 15:45:12 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *buf, char *line)
{
	int		i;
	int		j;
	char	*concatenation;

	i = 0;
	j = 0;
	if (!buf || !line)
		return (NULL);
	concatenation = ft_calloc((ft_strlen(buf) + ft_strlen(line) + 1),
			sizeof(char *));
	if (!concatenation)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
	{
		concatenation[i] = buf[i];
		i++;
	}
	while (line[j])
	{
		concatenation[i] = line[j];
		i++;
		j++;
	}
	return (concatenation);
}

void	*ft_bzero(void *memo, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)memo)[i] = '\0';
		i++;
	}
	return (memo);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory_zone;

	if (size > 0 && count > SIZE_MAX / size)
		return (0);
	memory_zone = malloc(count * size);
	if (!memory_zone)
		return (NULL);
	ft_bzero(memory_zone, (count * size));
	return (memory_zone);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(((char *)src)) + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (((char *)dest));
}
