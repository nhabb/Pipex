/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:33:28 by nhaber            #+#    #+#             */
/*   Updated: 2024/07/11 12:21:09 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tohex(unsigned int hex, char *a)
{
	int	count;
	int	x;

	count = 0;
	if (hex == 0)
		return (0);
	x = hex % 16;
	count = ft_tohex(hex / 16, a);
	if (x >= 0 && x <= 15)
	{
		write(1, &a[x], 1);
		count++;
	}
	return (count);
}

int	ft_printhex(unsigned int hex, char c)
{
	int		count;
	char	*a;

	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (c == 'x')
	{
		a = "0123456789abcdef";
		count = ft_tohex(hex, a);
	}
	else if (c == 'X')
	{
		a = "0123456789ABCDEF";
		count = ft_tohex(hex, a);
	}
	return (count);
}
// int main()
// {
// 	unsigned int hex = 154;
// 	char	c = 'X';
// 	int	i;
// 	i = ft_printhex(hex, c);
// 	printf("\n%d", i);
// 	return (0);
// }