/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:52:16 by isporras          #+#    #+#             */
/*   Updated: 2023/05/21 11:52:16 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

int		*ft_argvtoint(int argc, char **argv);
t_stack	*ft_stacklstnewnode(int value, int pos);
t_stack	*ft_stacklstlast(t_stack **lst);
void	ft_stacklstadd_back(t_stack **lst, t_stack *new);
void	ft_stacklstadd_front(t_stack **lst, t_stack *new);
void	ft_arraytolist(t_stack **stack, int *array, int len);
void	ft_stackpushfirstlst(t_stack **a , t_stack **b);
void	ft_do_pa(t_stack **a, t_stack **b);
void	ft_do_pb(t_stack **a, t_stack **b);
void	ft_do_sa(t_stack **a);
void	ft_do_sb(t_stack **b);
void	ft_do_ss(t_stack **a, t_stack **b);
void	ft_do_ra(t_stack **a);
void	ft_do_rb(t_stack **b);
void	ft_do_rr(t_stack **a, t_stack **b);
void	ft_do_rra(t_stack **a);
void	ft_do_rrb(t_stack **b);
void	ft_do_rrr(t_stack **a, t_stack **b);
void	ft_stackswap(t_stack **a);
void	ft_stackrotate(t_stack **a);
void	ft_stackreverserotate(t_stack **a);
t_stack	*ft_onebeforelast(t_stack **lst);
void	ft_print_stack(t_stack **stack);
int		ft_check_errors(int argc, char **argv, int *stack_a);
void	ft_set_index(t_stack **stack_a);
int		ft_stacksize(t_stack **stack_a);
void	ft_sort_3(t_stack **stack);
void	ft_bigsort(t_stack **a, t_stack **b);
void	ft_rev_sort_3(t_stack **stack);
int		ft_find_idx_max(t_stack **a);
void	ft_free(t_stack **a, t_stack **b,int *stack_a);
#endif