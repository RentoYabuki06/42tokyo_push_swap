/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:51:01 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/27 16:29:52 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

#define MAX_STACK_SIZE 1000

static int	get_median(t_stack **stack, int size)
{
	int		values[MAX_STACK_SIZE];
	t_node	*current;
	int		i;
	int		j;
	int		temp;

	if (size > MAX_STACK_SIZE)
		size = MAX_STACK_SIZE;
	current = (*stack)->top;
	i = 0;
	while (i < size && current != NULL)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
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
	return (values[size / 2]);
}

void	ft_sort_quick_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	median;
	int	i;
	int	pushed;

	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->top->value > (*stack_a)->top->next->value)
			ft_sa(stack_a);
		return ;
	}
	else
	{
		median = get_median(stack_a, size);
		i = 0;
		pushed = 0;
		while (i < size)
		{
			if ((*stack_a)->top->value < median)
			{
				ft_pb(stack_a, stack_b);
				pushed++;
			}
			else
				ft_ra(stack_a);
			i++;
		}
		if (pushed == 0 || size - pushed == 0)
			return ;
		i = size - pushed;
		while (i > 0)
		{
			ft_rra(stack_a);
			i--;
		}
		ft_sort_quick_b(stack_a, stack_b, pushed);
		ft_sort_quick_a(stack_a, stack_b, size - pushed);
		while (pushed > 0)
		{
			ft_pa(stack_a, stack_b);
			pushed--;
		}
	}
}

void	ft_sort_quick_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	median;
	int	i;
	int	pushed;

	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_b)->top->value < (*stack_b)->top->next->value)
			ft_sb(stack_b);
		return ;
	}
	else
	{
		median = get_median(stack_b, size);
		i = 0;
		pushed = 0;
		while (i < size)
		{
			if ((*stack_b)->top->value >= median)
			{
				ft_pa(stack_a, stack_b);
				pushed++;
			}
			else
				ft_rb(stack_b);
			i++;
		}
		i = size - pushed;
		while (i > 0)
		{
			ft_rrb(stack_b);
			i--;
		}
		ft_sort_quick_a(stack_a, stack_b, pushed);
		ft_sort_quick_b(stack_a, stack_b, size - pushed);
		while (pushed > 0)
		{
			ft_pb(stack_a, stack_b);
			pushed--;
		}
	}
}
