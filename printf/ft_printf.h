/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaber <nhaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 22:21:02 by nhaber            #+#    #+#             */
/*   Updated: 2024/07/13 13:05:49 by nhaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int				ft_percent(char c);
int				ft_putchar(char c);
int				ft_countnumbers(int nb);
int				ft_putnbr(int nb);
int				ft_putstr(char *str);
int				ft_printptr(unsigned long hex);
int				ft_hexpointer(unsigned long int hex);
int				ft_tohex(unsigned int hex, char *a);
int				ft_printhex(unsigned int hex, char c);
int				in_set(char c, char *array);
int				ft_printf(const char *s, ...);
unsigned int	ft_unsigned_countnumbers(unsigned int nb);
unsigned int	ft_unsigned_putnumber(unsigned int nb);

#endif