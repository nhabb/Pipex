/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:20:54 by nhaber            #+#    #+#             */
/*   Updated: 2024/07/13 12:54:38 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexpointer(unsigned long int hex)
{
	int		count;
	int		x;
	char	*a;

	x = 0;
	count = 0;
	a = "0123456789abcdef";
	if (hex == 0)
		return (0);
	x = hex % 16;
	count = ft_hexpointer(hex / 16);
	if (x >= 0 && x < 16)
	{
		write(1, &a[x], 1);
		count++;
	}
	return (count);
}

int	ft_printptr(unsigned long hex)
{
	int	count;

	count = 0;
	if (hex == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = ft_hexpointer(hex);
	count += 2;
	return (count);
}
// int main()
// {
// 	int i;
// 	unsigned long int hex = 135173;
// 	i = ft_printptr((unsigned long long)hex);
// 	printf("\n%d", i);
// 	printf("\n%p", hex);
//	return (0);
//}