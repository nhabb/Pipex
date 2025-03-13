/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:48:46 by nhaber            #+#    #+#             */
/*   Updated: 2024/06/25 22:51:10 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tempc;
	t_list	*tempn;

	tempc = *lst;
	while (tempc != NULL)
	{
		tempn = tempc -> next;
		(*del)(tempc->content);
		free(tempc);
		tempc = tempn;
	}
	*lst = NULL;
}
