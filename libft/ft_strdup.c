/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:15:31 by nhaber            #+#    #+#             */
/*   Updated: 2024/06/19 12:46:15 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = ft_strlen(s);
	ptr = (char *)malloc(sizeof(*ptr) * (j + 1));
	while (i < j)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	if (!ptr)
		return (NULL);
	return (ptr);
}
