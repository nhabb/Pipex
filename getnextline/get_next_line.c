/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:55:07 by nhaber            #+#    #+#             */
/*   Updated: 2024/07/19 15:37:07 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	buffer_size = 0;
	static int	position = 0;
	static char	read_buffer[BUFFER_SIZE];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	return (readline(fd, &position, &buffer_size, read_buffer));
}
