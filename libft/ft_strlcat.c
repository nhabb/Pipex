/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:28:32 by nhaber            #+#    #+#             */
/*   Updated: 2024/06/14 12:47:55 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lenedst;
	size_t	lensrc;

	lenedst = ft_strlen(dst);
	lensrc = ft_strlen((char *) src);
	if (size <= lenedst)
		return (size + lensrc);
	i = lenedst;
	j = 0;
	while (src[j] && i < size -1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lenedst + lensrc);
}
