/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenault <jrenault@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:00:02 by jrenault          #+#    #+#             */
/*   Updated: 2022/12/03 16:12:29 by jrenault         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	search_return_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (0);
		i++;
	}
	if (buffer[i] == '\n')
		return (0);
	return (1);
}

void	clean_buffer(char *buffer)
{
	int		i;
	int		search;
	char	*temp;

	i = 0;
	search = search_return_line(buffer);
	temp = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char *)));
	if (search == 0)
	{
		while (buffer[i - 1] != '\n')
			i++;
		temp = ft_strdup(&buffer[i]);
		i = -1;
		while (temp[++i])
			buffer[i] = temp[i];
		buffer[i] = '\0';
		free(temp);
	}
	else
	{
		free(temp);
		buffer[0] = '\0';
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			nbyte;
	char		*line;

	line = ft_calloc(1, 1);
	nbyte = 1;
	while (search_return_line(buffer))
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte == -1)
			return (NULL);
		printf("%s", buffer);
		line = ft_strjoin_gnl(buffer, line);
		clean_buffer(buffer);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;

	fd = open("LeCorbeauEtLeRenard.txt", O_RDONLY);
	i = 1;
	while (i > 0)
	{
		get_next_line(fd);
//		printf("%s", get_next_line(fd));
		i--;
	}
	close(fd);
}