/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:10:27 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/08 13:13:38 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_node	*cur_node;

	if (!stack || !stack->top)
		return (0);
	cur_node = stack->top;
	while (cur_node->next)
	{
		if (cur_node->data > cur_node->next->data)
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}