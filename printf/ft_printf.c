/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 22:28:51 by nhaber            #+#    #+#             */
/*   Updated: 2024/07/13 13:00:19 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkconditions(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len = ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		len = ft_unsigned_putnumber(va_arg(arg, unsigned int));
	else if (c == 'X')
		len = ft_printhex(va_arg(arg, int), c);
	else if (c == 'x')
		len = ft_printhex(va_arg(arg, int), c);
	else if (c == '%')
		len = ft_percent(c);
	else if (c == 'p')
		len = ft_printptr(va_arg(arg, long unsigned int));
	return (len);
}

int	in_set(char c, char *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		if (c == array[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		length;
	va_list	arg;

	va_start (arg, s);
	length = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && in_set(s[i + 1], "cspdiuxX%"))
		{
			length += ft_checkconditions(arg, s[i + 1]);
			i++;
		}
		else
		{
			length += ft_putchar(s[i]);
		}
		i++;
	}
	va_end(arg);
	return (length);
}
