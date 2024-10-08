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

#include "../push_swap_bonus.h"

void	ft_do_ra(t_stack **a)
{
	ft_stackrotate(a);
}

void	ft_do_rb(t_stack **b)
{
	ft_stackrotate(b);
}

void	ft_do_rr(t_stack **a, t_stack **b)
{
	ft_stackrotate(a);
	ft_stackrotate(b);
}

void	ft_do_rra(t_stack **a)
{
	ft_stackreverserotate(a);
}

void	ft_do_rrb(t_stack **b)
{
	ft_stackreverserotate(b);
}
