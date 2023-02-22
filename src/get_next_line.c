/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctoptas <ctoptas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:32:22 by ctoptas           #+#    #+#             */
/*   Updated: 2023/02/21 15:35:31 by ctoptas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*myfree(void *str)
{
	free (str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int		rd_byte;
	int		i;
	char	buffer;
	char	*line;

	rd_byte = 1;
	i = 0;
	line = (char *)malloc(sizeof(char) * 8888);
	buffer = 0;
	if (fd < 0)
		return (NULL);
	while (rd_byte > 0)
	{
		rd_byte = read(fd, &buffer, 1);
		if (rd_byte <= 0)
			break ;
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
	}
	line[i] = '\0';
	if (!*line)
		myfree(line);
	return (line);
}
