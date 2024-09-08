/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:51:01 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/08 15:52:44 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_sort_large(t_stack **stack_a, t_stack **stack_b, int left, int right)
{
	int pivot;
	int i;
	int j;

	if (left >= right)
		return ;
	pivot = (*stack_a)->top->value;
	i = left;
	j = right;
	while (i <= j)
	{
		while ((*stack_a)->top->value < pivot)
			ft_ra(stack_a);
		while ((*stack_a)->top->value > pivot)
			ft_rra(stack_a);
		if (i <= j)
		{
			ft_sa(stack_a);
			i++;
			j--;
		}
	}
	ft_sort_large(stack_a, stack_b, left, j);
	ft_sort_large(stack_a, stack_b, i, right);
}
