/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:33:35 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/18 18:04:28 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_find_min(t_node *top)
{
	int		min;

	min = top->value;
	while (top)
	{
		if (top->value < min)
			min = top->value;
		top = top->next;
	}
	return (min);
}

static int	ft_find_max(t_node *top)
{
	int		max;

	max = top->value;
	while (top)
	{
		if (top->value > max)
			max = top->value;
		top = top->next;
	}
	return (max);
}

void	ft_sort_three(t_stack **stack)
{
	if ((*stack)->top->value > (*stack)->top->next->value
		&& (*stack)->top->value < (*stack)->top->next->next->value)
		ft_sa(stack);
	else if ((*stack)->top->value > (*stack)->top->next->value
		&& (*stack)->top->value > (*stack)->top->next->next->value)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
	else if ((*stack)->top->value < (*stack)->top->next->value
		&& (*stack)->top->value > (*stack)->top->next->next->value)
		ft_ra(stack);
	else if ((*stack)->top->value > (*stack)->top->next->value
		&& (*stack)->top->value > (*stack)->top->next->next->value)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if ((*stack)->top->value < (*stack)->top->next->value
		&& (*stack)->top->value < (*stack)->top->next->next->value)
		ft_rra(stack);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b, int size, int pushed)
{
	int	min;
	int max;

	min = ft_find_min((*stack_a)->top);
	max = ft_find_max((*stack_a)->top);
	while (size - pushed > 3)
	{
		if ((*stack_a)->top->value == min || (size == 5 && (*stack_a)->top->value == max))
		{
			ft_pb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_ra(stack_a);
	}
	ft_sort_three(stack_a);
	while (pushed > 0)
	{
		ft_pa(stack_a, stack_b);
		pushed--;
		if ((*stack_a)->top->value == max)
			ft_ra(stack_a);
	}
}
