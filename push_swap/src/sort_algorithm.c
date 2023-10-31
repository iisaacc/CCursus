/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:14:58 by isporras          #+#    #+#             */
/*   Updated: 2023/10/05 16:14:58 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_idx_max(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = tmp->index;
	while (tmp)
	{
		if (tmp->index > i)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

//Manda a b todos los nodos del stack a menos los 3 mayores.
//Primero manda todos los que sean menores al indice medio y despues los mayores.
void	ft_send_b(t_stack **a, t_stack **b)
{
	int	total;
	int	maxidx;
	int	i;

	i = 0;
	maxidx = ft_find_idx_max(a);
	total = ft_stacksize(a);
	while (i < total)
	{
		if ((*a)->index < (maxidx - 2) && (*a)->index <= (total / 2))
			ft_do_pb(a,b);
		else
			ft_do_ra(a);
		i++;
	}
	i = 0;
	total = ft_stacksize(a);
	while (i < total && total > 3)
	{
		if ((*a)->index < (maxidx - 2))
			ft_do_pb(a,b);
		else
			ft_do_ra(a);
		i++;
	}
}

void	ft_refresh_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
	tmp = *b;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

//Localiza cual es el nodo objetivo en a para cada nodo de b,
//de forma que al hacer un pa el nodo de b quede bien colocado
void	ft_target_pos(t_stack **a, t_stack **b)
{
	t_stack *tmpa;
	t_stack *tmpb;
	int		dif;

	tmpb = *b;
	while(tmpb)
	{
		tmpa = *a;
		while (tmpa)
		{
			if(tmpa->index - tmpb->index > 0)
			{
				tmpb->target_pos = tmpa->pos;
				dif = tmpa->index - tmpb->index;
			}
			tmpa = tmpa->next;
		}
		tmpa = *a;
		while (tmpa)
		{
			if (((tmpa->index - tmpb->index) > 0) && ((tmpa->index - tmpb->index) < dif))
			{
				tmpb->target_pos = tmpa->pos;
				dif = tmpa->index - tmpb->index;
			}
			tmpa = tmpa->next;
		}
		tmpb = tmpb->next;
	}
}

//Setea los costes en a y en b en cada elemento de b
void	ft_get_cost(t_stack **a, t_stack **b)
{
	t_stack *tmpb;

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

//Calcula el elemento de b que es menos costoso mover a su target pos en A.
t_stack	*ft_cheapest(t_stack **b)
{
	int		cheapest;
	t_stack *tmpb;
	t_stack *cheapest_node;

	tmpb = *b;
	cheapest_node = tmpb;
	cheapest = (abs)(tmpb->cost_a) + (abs)(tmpb->cost_b);
	while (tmpb)
	{
		if (((abs)(tmpb->cost_a) + (abs)(tmpb->cost_b)) < cheapest)
		{
			cheapest = (abs)(tmpb->cost_a) + (abs)(tmpb->cost_b);
			cheapest_node = tmpb;
		}
		tmpb = tmpb->next;
	}
	return (cheapest_node);
}

//Basandose en los costes de cada nodo de b hace las acciones necesarias para llevarlo al stack a.
void	ft_do_actions(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_cheapest(b);
	while ((cheapest_node->cost_a > 0) && (cheapest_node->cost_b > 0))
	{
		ft_do_rr(a,b);
		cheapest_node->cost_a--;
		cheapest_node->cost_b--;
	}
	while ((cheapest_node->cost_a < 0) && (cheapest_node->cost_b < 0))
	{
		ft_do_rrr(a,b);
		cheapest_node->cost_a++;
		cheapest_node->cost_b++;
	}
	while ((cheapest_node->cost_a < 0) || (cheapest_node->cost_b < 0))
	{
		if(cheapest_node->cost_a < 0)
		{
			ft_do_rra(a);
			cheapest_node->cost_a++;
		}
		else if(cheapest_node->cost_b < 0)
		{
			ft_do_rrb(b);
			cheapest_node->cost_b++;
		}
	}
	while ((cheapest_node->cost_a > 0) || (cheapest_node->cost_b > 0))
	{
		if(cheapest_node->cost_a > 0)
		{
			ft_do_ra(a);
			cheapest_node->cost_a--;
		}
		else if(cheapest_node->cost_b > 0)
		{
			ft_do_rb(b);
			cheapest_node->cost_b--;
		}
	}
	ft_do_pa(a,b);
}

void	ft_finish_it(t_stack **a)
{
	while((*a)->index != 1)
		ft_do_rra(a);
}

void	ft_bigsort(t_stack **a, t_stack **b)
{
	ft_send_b(a, b);
	ft_sort_3(a);
	while (*b)
	{
		ft_refresh_pos(a,b);
		ft_target_pos(a,b);
		ft_get_cost(a,b);
		ft_do_actions(a,b);
	}
	ft_finish_it(a);
	ft_refresh_pos(a,b);
}

