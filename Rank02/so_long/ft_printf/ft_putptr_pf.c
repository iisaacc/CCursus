/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:22:23 by isporras          #+#    #+#             */
/*   Updated: 2023/05/03 14:44:16 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_pf(uintptr_t ptr, char *base, int *n)
{
	int	div;

	div = 16;
	if (ptr < 16)
		*n += ft_putchar_pf(base[ptr]);
	else
	{
		ft_putptr_pf(ptr / div, base, n);
		*n += ft_putchar_pf(base[ptr % div]);
	}
}
