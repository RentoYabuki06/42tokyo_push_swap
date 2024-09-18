/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:01:09 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/18 19:43:34 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_node	*tmp;
	t_node	*tmp_bottom;

	if (!(*stack) || (*stack)->size < 2)
		return ;
	tmp = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
	tmp->next = NULL;
	tmp_bottom = (*stack)->bottom;
	(*stack)->bottom = tmp;
	tmp_bottom->next = tmp;
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("ra\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
