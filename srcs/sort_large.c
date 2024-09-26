/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:51:01 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/26 21:34:03 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_get_pivot_value_for_range(t_stack **stack, int size)
{
	int		i;
	int		pivot;
	t_node	*current;
	t_node	*sorted;

	current = (*stack)->top;
	sorted = current;
	i = 0;
	while (i < size)
	{
		t_node	*next = current->next;
		while (next)
		{
			if (current->value > next->value)
			{
				int temp = current->value;
				current->value = next->value;
				next->value = temp;
			}
			next = next->next;
		}
		current = current->next;
		i++;
	}
	pivot = sorted->value;
	return (pivot);
}


static int	ft_div_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pivot;
	int	num_pushed;
	int	num_rotated;
	int original_size = size;

	pivot = ft_get_pivot_value_for_range(stack_a, size);
	num_pushed = 0;
	while (size > 0)
	{
		if ((*stack_a)->top == NULL)
			break;
		if ((*stack_a)->top->value < pivot)
		{
			num_pushed++;
			ft_pb(stack_a, stack_b);
		}
		else
			ft_ra(stack_a);
		size--;
	}
	num_rotated = original_size - num_pushed;
	while (num_rotated-- > 0)
		ft_rra(stack_a);
	return (num_pushed);
}

static int	ft_div_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	pivot;
	int	num_pushed;
	int	num_rotated;
	int original_size = size;

	pivot = ft_get_pivot_value_for_range(stack_b, size);
	num_pushed = 0;
	while (size > 0)
	{
		if ((*stack_b)->top == NULL)
			break;
		if ((*stack_b)->top->value < pivot)
		{
			num_pushed++;
			ft_pa(stack_a, stack_b);
		}
		else
			ft_rb(stack_b);
		size--;
	}
	num_rotated = original_size - num_pushed;
	while (num_rotated-- > 0)
		ft_rrb(stack_b);
	return (num_pushed);
}

void	ft_sort_quick_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	num_pushed;
	int	num_rotated;

	if (size <= 1 || !stack_a || !(*stack_a) || !((*stack_a)->top))
		return ;
	if (size == 2 && ((*stack_a)->top->value > (*stack_a)->top->next->value))
		ft_sa(stack_a);
	if (size == 2)
		return ;
	num_pushed = ft_div_a(stack_a, stack_b, size);
	if (num_pushed > 0)
		ft_sort_quick_a(stack_a, stack_b, size - num_pushed);
	if (num_pushed > 0)
		ft_sort_quick_b(stack_a, stack_b, num_pushed);
	num_rotated = num_pushed;
	while (num_rotated-- > 0)
	{
		ft_rb(stack_b);
		ft_pa(stack_a, stack_b);
		ft_rrb(stack_b);
	}
}

void	ft_sort_quick_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	num_pushed;
	int	num_rotated;

	if (size <= 1 || !stack_b || !(*stack_b) || !((*stack_b)->top))
		return ;
	if (size == 2 && ((*stack_b)->top->value > (*stack_b)->top->next->value))
		ft_sb(stack_b);
	if (size == 2)
		return ;
	num_pushed = ft_div_b(stack_b, stack_a, size);
	if (num_pushed > 0)
		ft_sort_quick_b(stack_a, stack_b, size - num_pushed);
	if (num_pushed > 0)
		ft_sort_quick_a(stack_a, stack_b, num_pushed);
	num_rotated = num_pushed;
	while (num_rotated-- > 0)
	{
		ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
		ft_rra(stack_a);
	}
}
