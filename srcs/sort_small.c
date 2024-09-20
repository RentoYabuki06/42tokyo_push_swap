/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:33:35 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/20 16:09:01 by ryabuki          ###   ########.fr       */
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

void	ft_sort_three(t_stack **stack, int first, int second, t_list **cmndlist)
{
	int	third;

	third = (*stack)->top->next->next->value;
	if (first > second && first < third)
		ft_sa(stack, cmndlist);
	else if (first < third && third < second)
	{
		ft_ra(stack, cmndlist);
		ft_sa(stack, cmndlist);
		ft_rra(stack, cmndlist);
	}
	else if (first < second && first > third)
	{
		ft_ra(stack, cmndlist);
		ft_ra(stack, cmndlist);
	}
	else if (first > third && second < third)
		ft_ra(stack, cmndlist);
	else
	{
		ft_sa(stack, cmndlist);
		ft_rra(stack, cmndlist);
	}
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	int	min;
	int	first;
	int	second;

	min = ft_find_min((*stack_a)->top);
	while ((*stack_a)->size > 3)
	{
		if ((*stack_a)->top->value == min)
			ft_pb(stack_a, stack_b, cmndlist);
		else
			ft_ra(stack_a, cmndlist);
	}
	if (!ft_is_sorted(stack_a))
	{
		first = (*stack_a)->top->value;
		second = (*stack_a)->top->next->value;
		ft_sort_three(stack_a, first, second, cmndlist);
	}
	ft_pa(stack_a, stack_b, cmndlist);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	int	min;
	int	max;

	min = ft_find_min((*stack_a)->top);
	max = ft_find_max((*stack_a)->top);
	while ((*stack_a)->size > 3)
	{
		if ((*stack_a)->top->value == min || (*stack_a)->top->value == max)
			ft_pb(stack_a, stack_b, cmndlist);
		else
			ft_ra(stack_a, cmndlist);
	}
	if (!ft_is_sorted(stack_a))
		ft_sort_three(stack_a, (*stack_a)->top->value, \
			(*stack_a)->top->next->value, cmndlist);
	ft_pa(stack_a, stack_b, cmndlist);
	if ((*stack_a)->top->value == max)
		ft_ra(stack_a, cmndlist);
	ft_pa(stack_a, stack_b, cmndlist);
	if ((*stack_a)->top->value == max)
		ft_ra(stack_a, cmndlist);
}
