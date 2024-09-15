/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:57:35 by ryabuki           #+#    #+#             */
/*   Updated: 2024/09/15 13:09:15 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_stack **stack)
{
	t_node	*tmp;

	if ((*stack)->size == 0)
	{
		ft_printf("note : This stack is empty!");
		return ;
	}
	ft_printf("-----  Printing Stack (Top to Down)  -------\n");
	tmp = ((*stack)->top);
	while (TRUE)
	{
		ft_printf("[%d]\n", tmp->value);
		tmp = tmp->next;
		if (tmp != (*stack)->bottom)
			break ;
	}
	ft_printf("--------  Finish!!  -------\n");
}
