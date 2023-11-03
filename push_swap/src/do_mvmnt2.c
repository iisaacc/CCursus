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

void	ft_do_ra(t_stack **a)
{
	ft_stackrotate(a);
	write(1, "ra\n", 3);
}

void	ft_do_rb(t_stack **b)
{
	ft_stackrotate(b);
	write(1, "rb\n", 3);
}

void	ft_do_rr(t_stack **a, t_stack **b)
{
	ft_stackrotate(a);
	ft_stackrotate(b);
	write(1, "rr\n", 3);
}

void	ft_do_rra(t_stack **a)
{
	ft_stackreverserotate(a);
	write(1, "rra\n", 4);
}

void	ft_do_rrb(t_stack **b)
{
	ft_stackreverserotate(b);
	write(1, "rrb\n", 4);
}
