/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:04:56 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/27 16:17:31 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_push(t_stack **from, t_stack **to)
{
	t_node	*tmp;

	if (!(*from) || !(*to) || (*from)->size == 0)
	{
		ft_printf("Stack is empty\n");
		return ;
	}
	tmp = (*from)->top;
	(*from)->top = (*from)->top->next;
	(*from)->size--;
	tmp->next = (*to)->top;
	(*to)->top = tmp;
	(*to)->size++;
	if ((*to)->size == 1)
		(*to)->bottom = tmp;
	if ((*from)->size == 0)
		(*from)->bottom = NULL;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
