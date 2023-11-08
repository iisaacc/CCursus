/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:23:48 by isporras          #+#    #+#             */
/*   Updated: 2023/05/21 12:23:48 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stackpushfirstlst(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
}

void	ft_stackswap(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->next;
	(*a)->next = ((*a)->next)->next;
	tmp->next = *a;
	*a = tmp;
}

void	ft_stackrotate(t_stack **a)
{
	t_stack	*last;
	t_stack	*second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	second = (*a)->next;
	last = ft_stacklstlast(a);
	last->next = *a;
	(*a)->next = NULL;
	*a = second;
}

void	ft_stackreverserotate(t_stack **a)
{
	t_stack	*last;
	t_stack	*onebefore;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = ft_stacklstlast(a);
	onebefore = ft_onebeforelast(a);
	last->next = *a;
	onebefore->next = NULL;
	*a = last;
}
