/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:15:06 by nhaber            #+#    #+#             */
/*   Updated: 2024/06/25 22:55:24 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlinkedlist;

	newlinkedlist = malloc(sizeof(t_list));
	if (!newlinkedlist)
	{
		return (NULL);
	}
	newlinkedlist -> content = content;
	newlinkedlist -> next = NULL;
	return (newlinkedlist);
}
