/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:04:56 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/20 16:04:52 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_push(t_stack **from, t_stack **to)
{
	t_node	*tmp;

	if (!(*from) || !(*to) || (*from)->size == 0)
		return ;
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

void	ft_pa(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	ft_push(stack_b, stack_a);
	if (cmndlist)
		ft_lstadd_back(cmndlist, ft_lstnew("pa"));
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	ft_push(stack_a, stack_b);
	if (cmndlist)
		ft_lstadd_back(cmndlist, ft_lstnew("pb"));
}
