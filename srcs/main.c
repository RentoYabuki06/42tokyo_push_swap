/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:26:06 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/08 15:02:48 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_is_sorted(t_stack **stack)
{
	t_node	*cur_node;

	if (!(*stack) || !(*stack)->top)
		return (0);
	cur_node = (*stack)->top;
	while (cur_node->next)
	{
		if (cur_node->value > cur_node->next->value)
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}

static void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_is_sorted(*stack_a))
		return ;
	if ((*stack_a)->size == 2)
	{
		ft_sa(stack_a);
		return ;
	}
	if ((*stack_a)->size == 3)
	{
		ft_sort_three(stack_a);
		return ;
	}
	if ((*stack_a)->size == 5)
	{
		ft_sort_five(stack_a, stack_b);
		return ;
	}
	ft_sort_large(stack_a, stack_b);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (0);
	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	if (!ft_check(argc, argv))
		return (0);
	if (!ft_fill_stack(&stack_a, argc, argv))
		return (0);
	ft_push_swap(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
