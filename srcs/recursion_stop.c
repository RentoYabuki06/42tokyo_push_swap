/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_stop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:44:55 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/07 19:49:49 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rec_stop(t_stack **stack_a, t_stack **stack_b, int size, int flag)
{
	if (size <= 1)
		return ;
	if (flag == 0 && size == 2 && (*stack_a)->top->value > (*stack_a)->top->next->value)
		ft_sa(stack_a);
	if (flag == 1 && size == 2 && (*stack_b)->top->value < (*stack_b)->top->next->value)
		ft_sb(stack_b);
	if (size == 2)
		return ;
}
