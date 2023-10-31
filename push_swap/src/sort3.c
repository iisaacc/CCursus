/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:15:04 by isporras          #+#    #+#             */
/*   Updated: 2023/10/30 11:15:04 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_3(t_stack **stack)
{
	if ((*stack)->index == ft_find_idx_max(stack))
		ft_do_ra(stack);
	if (((*stack)->next)->index == ft_find_idx_max(stack))
		ft_do_rra(stack);
	if ((*stack)->index > ((*stack)->next)->index)
		ft_do_sa(stack);
	else
		return;
}

void	ft_rev_sort_3(t_stack **stack)
{
	if ((*stack)->index == (ft_find_idx_max(stack) - 2))
		ft_do_ra(stack);
	if (((*stack)->next)->index == (ft_find_idx_max(stack) - 2))
		ft_do_rra(stack);
	if ((*stack)->index < ((*stack)->next)->index)
		ft_do_sa(stack);
	else
		return;
}