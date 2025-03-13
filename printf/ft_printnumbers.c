/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:22:07 by nhaber            #+#    #+#             */
/*   Updated: 2024/07/13 12:54:52 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countnumbers(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		nb = 147483648;
		count += 2;
	}
	while (nb < 0)
	{
		nb *= -1;
		count++;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = ft_countnumbers(nb);
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	return (count);
}

unsigned int	ft_unsigned_countnumbers(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (0);
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

unsigned int	ft_unsigned_putnumber(unsigned int nb)
{
	int	i;

	i = ft_unsigned_countnumbers(nb);
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb >= 10)
	{
		ft_unsigned_putnumber(nb / 10);
		ft_unsigned_putnumber(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	return (i);
}

// int main() {
//     int num1 = 123;
//     int num2 = 6789;
// 	unsigned int num3 = 0;
// 	int	i = 0;
// 	int	j = 0;
// 	int k = 0;
//     i = ft_putnbr(num1);
//     ft_putchar('\n');
//     j = ft_putnbr(num2);
//     ft_putchar('\n');
// 	k = ft_unsigned_putnumber(num3);
// 	printf ("\n%d \n%d \n%d", i, j, k);
//     return 0;
// }