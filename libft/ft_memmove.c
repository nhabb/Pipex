/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:18:47 by nhaber            #+#    #+#             */
/*   Updated: 2024/06/14 11:54:29 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = src;
	size_t				i;

	d = dest;
	if (d < s)
	{
		i = 0;
		while (n-- > 0)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (n-- > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}
