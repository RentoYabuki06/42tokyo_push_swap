/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:33:35 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 23:39:03 by yabukirento      ###   ########.fr       */
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

void	ft_sort_three(t_stack **stack, int first, int second, int third)
{
	first = (*stack)->top->value;
	second = (*stack)->top->next->value;
	third = (*stack)->top->next->next->value;
	if (first > second && first < third)
		ft_sa(stack);
	else if (first < third && third < second)
	{
		ft_ra(stack);
		ft_sa(stack);
		ft_rra(stack);
	}
	else if (first < second && first > third)
	{
		ft_ra(stack);
		ft_ra(stack);
	}
	else if (first > third && second < third)
	{
		ft_ra(stack);
	}
	else
	{
		ft_sa(stack);
		ft_rra(stack);
	}
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_find_min((*stack_a)->top);
	while ((*stack_a)->size > 3)
	{
		if ((*stack_a)->top->value == min)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	if (!ft_is_sorted(stack_a))
		ft_sort_three(stack_a, 0, 0, 0);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int max;

	min = ft_find_min((*stack_a)->top);
	max = ft_find_max((*stack_a)->top);
	while ((*stack_a)->size > 3)
	{
		if ((*stack_a)->top->value == min || (*stack_a)->top->value == max)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	if (!ft_is_sorted(stack_a))
		ft_sort_three(stack_a, 0, 0, 0);
	ft_pa(stack_a, stack_b);
	if ((*stack_a)->top->value == max)
		ft_ra(stack_a);
	ft_pa(stack_a, stack_b);
	if ((*stack_a)->top->value == max)
		ft_ra(stack_a);
}
