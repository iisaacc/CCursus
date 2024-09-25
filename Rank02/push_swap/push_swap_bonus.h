/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isporras <isporras@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:24:44 by isporras          #+#    #+#             */
/*   Updated: 2023/10/30 12:24:44 by isporras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

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

void	ft_stackpushfirstlst(t_stack **a, t_stack **b);
void	ft_stackswap(t_stack **a);
void	ft_stackrotate(t_stack **a);
void	ft_stackreverserotate(t_stack **a);
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
int		ft_check_errors(int argc, char **argv, int *stack_a);
t_stack	*ft_stacklstnewnode(int value, int pos);
t_stack	*ft_stacklstlast(t_stack **lst);
void	ft_stacklstadd_back(t_stack **lst, t_stack *new);
void	ft_stacklstadd_front(t_stack **lst, t_stack *new);
void	ft_arraytolist(t_stack **stack, int *array, int len);
t_stack	*ft_onebeforelast(t_stack **lst);
void	ft_print_stack(t_stack **stack);
int		*ft_argvtoint(int argc, char **argv);
void	ft_free(t_stack **a, t_stack **b, int *stack_a);
char	*ft_read(size_t bufsize);
void	ft_do(char *output, t_stack **a, t_stack **b);
char	*ft_read(size_t bufsize);
void	ft_is_ordered(t_stack **a, t_stack **b);
void	ft_set_index(t_stack **a);
int		ft_correct_input(char *output);
#endif