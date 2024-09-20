/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:51:01 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/20 19:41:39 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_quicksort_array(int *array, int low, int high, int i)
{
	int	pivot;
	int	j;
	int	temp;

	if (low < high)
	{
		pivot = array[high];
		j = low;
		while (j < high)
		{
			if (array[j] <= pivot)
			{
				i++;
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		ft_quicksort_array(array, low, i, low - 1);
		ft_quicksort_array(array, i + 2, high, i + 1);
	}
}

static int	ft_get_pivot_value_for_range(t_stack **stack_a, \
	t_stack **stack_b, int size, t_list **cmndlist)
{
	int		i;
	int		*array;
	int		pivot;
	t_node	*current;

	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		ft_error(stack_a, stack_b, cmndlist);
	current = (*stack_a)->top;
	i = 0;
	while (i < size)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	ft_quicksort_array(array, 0, size - 1, -1);
	pivot = array[size / 2];
	free(array);
	return (pivot);
}

static int	ft_div(t_stack **stack_a, t_stack **stack_b, int size, t_list **cmd)
{
	int	pivot;
	int	num_pushed;
	int	num_rotated;

	pivot = ft_get_pivot_value_for_range(stack_a, stack_b, size, cmd);
	num_pushed = 0;
	while (size > 0)
	{
		if ((*stack_a)->top == NULL)
			break ;
		if ((*stack_a)->top->value < pivot)
			num_pushed++;
		if ((*stack_a)->top->value < pivot)
			ft_pb(stack_a, stack_b, cmd);
		else
			ft_ra(stack_a, cmd);
		size--;
	}
	num_rotated = size - num_pushed;
	while (num_rotated-- > 0)
		ft_rra(stack_a, cmd);
	return (num_pushed);
}

static void	ft_sort_quick(t_stack **stack_a, \
	t_stack **stack_b, int size, t_list **cmndlist)
{
	int	num_pushed;

	if (size <= 1 || !stack_a || !(*stack_a) || !((*stack_a)->top))
		return ;
	if (size == 2 && ((*stack_a)->top->value > (*stack_a)->top->next->value))
		ft_sa(stack_a, cmndlist);
	if (size == 2)
		return ;
	num_pushed = ft_div(stack_a, stack_b, size, cmndlist);
	if (num_pushed > 0)
		ft_sort_quick(stack_a, stack_b, size - num_pushed, cmndlist);
	if (num_pushed > 0)
		ft_sort_quick(stack_b, stack_a, num_pushed, cmndlist);
	while (num_pushed > 0)
	{
		size = 0;
		while (size++ < num_pushed - 1)
			ft_rb(stack_b, cmndlist);
		ft_pa(stack_a, stack_b, cmndlist);
		while (size--)
			ft_rrb(stack_b, cmndlist);
		num_pushed--;
	}
	return ;
}

void	ft_sort_large(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	int	size;

	if (!cmndlist)
		ft_error(stack_a, stack_b, cmndlist);
	if (!stack_a || !(*stack_a) || !((*stack_a)->top))
		return ;
	size = (*stack_a)->size;
	if (size <= 1)
		return ;
	ft_sort_quick(stack_a, stack_b, size, cmndlist);
}
