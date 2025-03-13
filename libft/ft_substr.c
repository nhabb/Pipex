/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:03:07 by nhaber            #+#    #+#             */
/*   Updated: 2024/06/23 12:09:30 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	strlen;
	size_t	str;

	str = 0;
	strlen = ft_strlen (s);
	if (!s)
		return (0);
	while (start < strlen && (str < len && s[start + str]))
		str++;
	ptr = malloc(sizeof(char) * (str + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (start < strlen && i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
