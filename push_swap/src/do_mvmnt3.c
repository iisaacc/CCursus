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

void	ft_do_rrr(t_stack **a, t_stack **b)
{
	ft_stackreverserotate(a);
	ft_stackreverserotate(b);
	write(1, "rrr\n", 4);
}
