/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:49:37 by nhaber            #+#    #+#             */
/*   Updated: 2024/06/19 13:29:46 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != '\0' && size > (size_t) - 1 / nmemb)
		return (NULL);
	ptr = malloc((nmemb) * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size * nmemb);
	return (ptr);
}
