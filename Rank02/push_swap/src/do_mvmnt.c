/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_mvmnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:14:15 by isporras          #+#    #+#             */
/*   Updated: 2023/10/30 11:14:15 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_do_pa(t_stack **a, t_stack **b)
{
	ft_stackpushfirstlst(b, a);
	write(1, "pa\n", 3);
}

void	ft_do_pb(t_stack **a, t_stack **b)
{
	ft_stackpushfirstlst(a, b);
	write(1, "pb\n", 3);
}

void	ft_do_sa(t_stack **a)
{
	ft_stackswap(a);
	write(1, "sa\n", 3);
}

void	ft_do_sb(t_stack **b)
{
	ft_stackswap(b);
	write(1, "sb\n", 3);
}

void	ft_do_ss(t_stack **a, t_stack **b)
{
	ft_stackswap(a);
	ft_stackswap(b);
	write(1, "ss\n", 3);
}
