/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:02:11 by isporras          #+#    #+#             */
/*   Updated: 2023/05/21 13:02:11 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_double_rot(t_stack	*cheapest_node, t_stack **a, t_stack **b)
{
	while ((cheapest_node->cost_a > 0) && (cheapest_node->cost_b > 0))
	{
		ft_do_rr(a, b);
		cheapest_node->cost_a--;
		cheapest_node->cost_b--;
	}
	while ((cheapest_node->cost_a < 0) && (cheapest_node->cost_b < 0))
	{
		ft_do_rrr(a, b);
		cheapest_node->cost_a++;
		cheapest_node->cost_b++;
	}
}

void	ft_single_rot_pos(t_stack	*cheapest_node, t_stack **a, t_stack **b)
{
	while ((cheapest_node->cost_a > 0) || (cheapest_node->cost_b > 0))
	{
		if (cheapest_node->cost_a > 0)
		{
			ft_do_ra(a);
			cheapest_node->cost_a--;
		}
		else if (cheapest_node->cost_b > 0)
		{
			ft_do_rb(b);
			cheapest_node->cost_b--;
		}
	}
}

void	ft_single_rot_neg(t_stack	*cheapest_node, t_stack **a, t_stack **b)
{
	while ((cheapest_node->cost_a < 0) || (cheapest_node->cost_b < 0))
	{
		if (cheapest_node->cost_a < 0)
		{
			ft_do_rra(a);
			cheapest_node->cost_a++;
		}
		else if (cheapest_node->cost_b < 0)
		{
			ft_do_rrb(b);
			cheapest_node->cost_b++;
		}
	}
}

//Coge el array de argumentos y lo convierte en un array de enteros
int	*ft_argvtoint(int argc, char **argv)
{
	int		*stack;
	int		i;
	long	num;

	i = 0;
	stack = ft_calloc((argc - 1), sizeof(int));
	while (i < argc - 1)
	{
		num = ft_atoi_mod(argv[i + 1]);
		if (num < -2147483648 || num > 2147483647)
			return (NULL);
		else
			stack[i] = (int)num;
		i++;
	}
	return (stack);
}

void	ft_free(t_stack **a, t_stack **b, int *stack_a)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	t_stack	*aux;

	aux = NULL;
	tmpa = *a;
	tmpb = *b;
	while (tmpa)
	{
		aux = tmpa;
		tmpa = tmpa->next;
		free(aux);
	}
	while (tmpb)
	{
		aux = tmpb;
		tmpb = tmpb->next;
		free(aux);
	}
	free(stack_a);
}
