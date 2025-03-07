/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:51:01 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/07 19:40:27 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_copy_stack_values(t_stack *stack, int *values, int size)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack->top;
	while (i < size && current != NULL)
	{
		values[i++] = current->value;
		current = current->next;
	}
}

static void	ft_sort_int_array(int *values, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] > values[j])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	ft_get_median(t_stack **stack, int size)
{
	int	values[MAX_STACK_SIZE];

	if (size > MAX_STACK_SIZE)
		size = MAX_STACK_SIZE;
	ft_copy_stack_values(*stack, values, size);
	ft_sort_int_array(values, size);
	return (values[size / 2]);
}

void	ft_sort_quick_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	median;
	int	i;
	int	pushed;

	if (size <= 1)
		return ;
	if (size == 2 && (*stack_a)->top->value > (*stack_a)->top->next->value)
		ft_sa(stack_a);
	if (size == 2)
		return ;
	median = ft_get_median(stack_a, size);
	i = 0;
	pushed = 0;
	while (i++ < size)
	{
		if ((*stack_a)->top->value < median)
			pushed += ft_pb_int(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	ft_rra_time(stack_a, size - pushed);
	ft_sort_quick_b(stack_a, stack_b, pushed);
	ft_sort_quick_a(stack_a, stack_b, size - pushed);
	while (pushed-- > 0)
		ft_pa(stack_a, stack_b);
}

void	ft_sort_quick_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	median;
	int	i;
	int	pushed;

	if (size <= 1)
		return ;
	if (size == 2 && (*stack_b)->top->value < (*stack_b)->top->next->value)
		ft_sb(stack_b);
	if (size == 2)
		return ;
	median = ft_get_median(stack_b, size);
	i = 0;
	pushed = 0;
	while (i++ < size)
	{
		if ((*stack_b)->top->value >= median)
			pushed += ft_pa_int(stack_a, stack_b);
		else
			ft_rb(stack_b);
	}
	ft_rrb_time(stack_b, size - pushed);
	ft_sort_quick_a(stack_a, stack_b, pushed);
	ft_sort_quick_b(stack_a, stack_b, size - pushed);
	while (pushed-- > 0)
		ft_pb(stack_a, stack_b);
}
