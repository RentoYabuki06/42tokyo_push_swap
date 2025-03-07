/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:33:35 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/07 19:34:19 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_two(t_stack **stack)
{
	int	size;

	size = (*stack)->size;
	if (size <= 1)
		return ;
	if ((*stack)->top->value > (*stack)->top->next->value)
		return ;
	ft_sa(stack);
}

static void	ft_sort_three_excec\
	(t_stack **stack_a, int first, int second, int third)
{

	if (first > second && first < third)
		ft_sa(stack_a);
	else if (first < third && third < second)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (first < second && first > third)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	else if (first > third && second < third)
		ft_ra(stack_a);
	else
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
}

void	ft_sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (ft_is_sorted(stack_a))
		return ;
	if ((*stack_a)->size <= 2)
		ft_sort_two(stack_a);
	first = (*stack_a)->top->value;
	second = (*stack_a)->top->next->value;
	third = (*stack_a)->top->next->next->value;
	ft_sort_three_excec(stack_a, first, second, third);
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
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;

	min = ft_find_min((*stack_a)->top);
	max = ft_find_max((*stack_a)->top);
	while ((*stack_a)->size > 3)
	{
		if ((*stack_a)->top->value == min || (*stack_a)->top->value == max)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	if ((*stack_a)->top->value == max)
		ft_ra(stack_a);
	ft_pa(stack_a, stack_b);
	if ((*stack_a)->top->value == max)
		ft_ra(stack_a);
}
