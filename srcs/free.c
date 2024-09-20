/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:17:49 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/20 17:07:19 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_free_stack(t_stack **stack)
{
	t_node	*cur_node;
	t_node	*next_node;

	if (!stack || !(*stack))
		return ;
	cur_node = (*stack)->top;
	while (cur_node)
	{
		next_node = cur_node->next;
		free(cur_node);
		cur_node = next_node;
	}
	free(*stack);
	*stack = NULL;
}

void	ft_free_all(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	if (!cmndlist || !(*cmndlist))
		return ;
	*cmndlist = NULL;
}
