/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:47:39 by isporras          #+#    #+#             */
/*   Updated: 2024/01/08 15:47:39 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include <stdarg.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str)
		len++;
	return (len);
}

int	ft_putstr(char *s)
{
	if (!s)
		write(1, "(null)", 6);
	else
		write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putnbr(int num)
{
	int	n;

	n = 0;
	if(num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		n++;
	}
	if (num > 9)
		ft_putnbr (num / 10);
	write(1, '0' + (num % 10), 1);
	n++;
	return (n);
}

int	ft_putvar(va_list var, char c)
{
	int	n;

	n = 0;
	if (c == 's')
		n += ft_putstr(va_arg(var, char *));
	else if (c == 'd')
		n += ft_putnbr(va_arg(var, int));
	else if (c == 'x')
		n += ft_puthexa(va_arg(var, char *));
	return (n);
}

int ft_printf(const char *str, ... )
{
	va_list	var;
	int		n;

	n = 0;
	if (!str)
		return (n);
	va_start(var, str);
	while (*str)
	{
		if (*str == '%')
		{
			n += ft_putvar(var, *(str + 1));
			str++;
		}
	}
}
