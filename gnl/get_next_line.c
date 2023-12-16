/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:44:53 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/15 02:44:16 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_and_alloc(char *buffer, int fd)
{
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > INT_MAX || read(fd, buffer, 0) < 0)
		return (free(buffer), buffer = NULL, NULL);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;

	buffer = check_and_alloc(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_strjoin_n(NULL, buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	if (check_str(buffer))
		return (line);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || (i == 0 && line[0] == '\0'))
			return (free(buffer), buffer = NULL, free(line), NULL);
		line = ft_strjoin_n(line, buffer);
		if (!line)
			return (free(buffer), buffer = NULL, NULL);
		if (check_str(buffer))
			return (line);
	}
	return (line);
}
