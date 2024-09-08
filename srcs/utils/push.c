/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:04:56 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/08 17:28:54 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void   ft_push(t_stack **from, t_stack **to)
{
	t_node *tmp;

	if (!(*from) || !(*to) || (*from)->size == 0)
		return ;
	tmp = (*from)->top;
	(*from)->top = (*from)->top->next;
	(*from)->size--;
	tmp->next = (*to)->top;
	(*to)->top = tmp;
	(*to)->size++;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
