/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:22:43 by isporras          #+#    #+#             */
/*   Updated: 2023/05/02 13:22:43 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putvar(va_list var, char c, int *n)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_pf(va_arg(var, int), n);
	else if (c == 's')
		*n += ft_putstr_pf(va_arg(var, char *));
	else if (c == 'c')
		*n += ft_putchar_pf(va_arg(var, int));
	else if (c == 'x')
		ft_putnbr_base(va_arg(var, int), "0123456789abcdef", n);
	else if (c == 'X')
		ft_putnbr_base(va_arg(var, int), "0123456789ABCDEF", n);
	else if (c == 'u')
		ft_putunsigned_pf(va_arg(var, unsigned int), n);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		*n += 2;
		ft_putptr_pf(va_arg(var, uintptr_t), "0123456789abcdef", n);
	}
	else if (c == '%')
		*n += ft_putchar_pf('%');
}
