/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:03:47 by nhaber            #+#    #+#             */
/*   Updated: 2024/07/19 15:36:20 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_addtoline(int line_len, char c, char *line_to_return)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(line_len + 2);
	if (!new)
		return (NULL);
	while (i < line_len)
	{
		new[i] = line_to_return[i];
		i++;
	}
	new[line_len] = c;
	new[line_len + 1] = '\0';
	free (line_to_return);
	return (new);
}

ssize_t	read_buffer(int fd, int *position,
						int *buffer_size, char *buffer)
{
	*buffer_size = read(fd, buffer, BUFFER_SIZE);
	*position = 0;
	return (*buffer_size);
}

char	*readline(int fd, int *position, int *buffer_size, char *buffer)
{
	int		line_len;
	char	*line_to_return;
	char	c;

	line_len = 0;
	line_to_return = NULL;
	while (1)
	{		
		if (*position >= *buffer_size)
		{
			if (read_buffer(fd, position, buffer_size, buffer) <= 0)
			{
				if (line_len > 0)
					return (line_to_return);
				free (line_to_return);
				return (NULL);
			}
		}
		c = buffer[(*position)++];
		line_to_return = ft_addtoline(line_len++, c, line_to_return);
		if (!line_to_return || c == '\n')
			break ;
	}
	return (line_to_return);
}
