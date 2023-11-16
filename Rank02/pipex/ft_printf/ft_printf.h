/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:48:53 by isporras          #+#    #+#             */
/*   Updated: 2023/05/03 14:48:53 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int		ft_printf(char const *str, ...);
void	ft_putvar(va_list var, char c, int *n);
int		ft_putnbr_pf(int arg, int *n);
int		ft_putunsigned_pf(unsigned int arg, int *n);
int		ft_putstr_pf(char *s);
int		ft_putchar_pf(char arg);
void	ft_putnbr_base(int nbr, char *base, int *n);
void	ft_putptr_pf(uintptr_t ptr, char *base, int *n);

#endif
