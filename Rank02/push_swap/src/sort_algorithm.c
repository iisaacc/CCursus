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
//Primero manda todos los que sean menores al indice medio
//y despues los mayores.
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
			ft_do_pb(a, b);
		else
			ft_do_ra(a);
		i++;
	}
	i = 0;
	total = ft_stacksize(a);
	while (i < total && total > 3)
	{
		if ((*a)->index < (maxidx - 2))
			ft_do_pb(a, b);
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

int	ft_get_dif(t_stack *ta, t_stack *tb)
{
	int		dif;

	while (ta)
	{
		if (ta->index - tb->index > 0)
		{
			tb->target_pos = ta->pos;
			dif = ta->index - tb->index;
		}
		ta = ta->next;
	}
	return (dif);
}

//Localiza cual es el nodo objetivo en a para cada nodo de b,
//de forma que al hacer un pa el nodo de b quede bien colocado
void	ft_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*ta;
	t_stack	*tb;
	int		dif;

	tb = *b;
	while (tb)
	{
		ta = *a;
		dif = ft_get_dif(ta, tb);
		while (ta)
		{
			if (ta->index - tb->index > 0 && ta->index - tb->index < dif)
			{
				tb->target_pos = ta->pos;
				dif = ta->index - tb->index;
			}
			ta = ta->next;
		}
		tb = tb->next;
	}
}
