/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additonal_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:56:58 by ryabuki           #+#    #+#             */
/*   Updated: 2024/09/27 17:57:11 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra_time(t_stack **stack_a, int times)
{
	while (times-- > 0)
		ft_rra(stack_a);
}

void	ft_rrb_time(t_stack **stack_b, int times)
{
	while (times-- > 0)
		ft_rrb(stack_b);
}
