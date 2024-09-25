/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:33:08 by isporras          #+#    #+#             */
/*   Updated: 2023/11/02 12:33:08 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Setea los costes en a y en b en cada elemento de b
void	ft_get_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmpb;

	tmpb = *b;
	while (tmpb)
	{
		if (tmpb->pos <= ft_stacksize(b) / 2)
			tmpb->cost_b = tmpb->pos;
		else if (tmpb->pos > ft_stacksize(b) / 2)
			tmpb->cost_b = tmpb->pos - ft_stacksize(b);
		if (tmpb->target_pos <= ft_stacksize(a) / 2)
			tmpb->cost_a = tmpb->target_pos;
		else if (tmpb->target_pos > ft_stacksize(a) / 2)
			tmpb->cost_a = tmpb->target_pos - ft_stacksize(a);
		tmpb = tmpb->next;
	}
}

int	ft_calculate_cost(int cost_a, int cost_b)
{
	int	cost;

	cost = 0;
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if ((abs)(cost_a) >= (abs)(cost_b))
			cost = (abs)(cost_a);
		else
			cost = (abs)(cost_b);
	}
	else
		cost = (abs)(cost_a) + (abs)(cost_b);
	return (cost);
}

//Calcula el elemento de b que es menos costoso mover a su target pos en A.
t_stack	*ft_cheapest(t_stack **b)
{
	int		cost;
	t_stack	*tmpb;
	t_stack	*cheapest_node;

	tmpb = *b;
	cheapest_node = tmpb;
	cost = ft_calculate_cost(tmpb->cost_a, tmpb->cost_b);
	while (tmpb)
	{
		if (ft_calculate_cost(tmpb->cost_a, tmpb->cost_b) < cost)
		{
			cost = ft_calculate_cost(tmpb->cost_a, tmpb->cost_b);
			cheapest_node = tmpb;
		}
		tmpb = tmpb->next;
	}
	return (cheapest_node);
}

//Basandose en los costes de cada nodo de b hace las acciones
//necesarias para llevarlo al stack a.
void	ft_do_actions(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_cheapest(b);
	if (((cheapest_node->cost_a > 0) && (cheapest_node->cost_b > 0))
		|| ((cheapest_node->cost_a < 0) && (cheapest_node->cost_b < 0)))
		ft_double_rot(cheapest_node, a, b);
	if ((cheapest_node->cost_a > 0) || (cheapest_node->cost_b > 0))
		ft_single_rot_pos(cheapest_node, a, b);
	if ((cheapest_node->cost_a < 0) || (cheapest_node->cost_b < 0))
		ft_single_rot_neg(cheapest_node, a, b);
	ft_do_pa(a, b);
}

void	ft_bigsort(t_stack **a, t_stack **b)
{
	ft_send_b(a, b);
	ft_sort_3(a);
	while (*b)
	{
		ft_refresh_pos(a, b);
		ft_target_pos(a, b);
		ft_get_cost(a, b);
		ft_do_actions(a, b);
	}
	ft_finish_it(a);
	ft_refresh_pos(a, b);
}
