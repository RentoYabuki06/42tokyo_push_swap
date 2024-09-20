/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:18:02 by ryabuki           #+#    #+#             */
/*   Updated: 2024/09/20 16:18:07 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack **stack)
{
	t_node	*cur_node;

	if (!(*stack) || !(*stack)->top)
		return (1);
	cur_node = (*stack)->top;
	while (cur_node->next)
	{
		if (cur_node->value > cur_node->next->value)
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}
