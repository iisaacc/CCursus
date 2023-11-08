/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:36:31 by isporras          #+#    #+#             */
/*   Updated: 2023/05/08 14:41:49 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, char *base, int *n)
{
	unsigned int	div;
	unsigned int	num;

	if (nbr < 0)
		num = -nbr;
	div = 16;
	num = nbr;
	if (num < 16)
		*n += ft_putchar_pf(base[num]);
	else
	{
		ft_putnbr_base(nbr / div, base, n);
		*n += ft_putchar_pf(base[nbr % div]);
	}
}
