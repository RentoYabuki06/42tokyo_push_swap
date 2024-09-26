/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:00:52 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/26 19:01:33 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	*stack_a = ft_init_stack();
	*stack_b = ft_init_stack();
	*cmndlist = ft_lstnew("start");
	if (!cmndlist)
		ft_error(stack_a, stack_b, cmndlist);
}

t_stack	*ft_init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}
