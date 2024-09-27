/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:15:40 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/27 16:10:43 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include "../srcs/ft_printf/ft_printf.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

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

void	ft_swap(t_stack **stack);
bool	ft_is_one(char *s);
t_stack	*ft_init_stack(void);
void	ft_init(t_stack **stack_a, t_stack **stack_b);
int		ft_atoi_ps(char *s);
int		ft_is_sorted(t_stack **stack);
int		ft_fill(t_stack **stack_a, char **split);
void	ft_sort_three(t_stack **stack, int first, int second);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void	ft_error(t_stack **stack_a, t_stack **stack_b, char **split);
void	ft_free_all(t_stack **stack_a, t_stack **stack_b, char **split);
void	ft_free_split(char **split);
void	ft_sort_quick_a(t_stack **stack_a, t_stack **stack_b, int size);
void	ft_sort_quick_b(t_stack **stack_a, t_stack **stack_b, int size);

#endif
