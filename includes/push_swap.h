/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:15:40 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/14 12:00:02 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"

typedef struct s_node
{
	int value;
	struct s_node *next;
} t_node;

typedef struct s_stack {
	t_node *top;
	t_node *bottom;
	int size;
} t_stack;

void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_b, t_stack **stack_a);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
int		ft_atoi_pushswap(const char *str);
int		ft_init_check(int argc, char **argv);
void	ft_free_stack(t_stack **stack);
t_stack	*ft_init_stack(void);
int		ft_fill_stack(t_stack **stack, int argc, char **argv);
void	ft_sort_three(t_stack **stack);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_large(t_stack **stack_a, t_stack **stack_b, int left, int right);

#endif
