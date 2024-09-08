/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:01:09 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/08 13:39:00 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_node	*tmp;

	if (!(*stack) || (*stack)->size < 2)
		return ;
	tmp = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
	tmp->next = NULL;
	(*stack)->bottom = tmp;
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}