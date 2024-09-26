/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 21:20:57 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/26 20:14:38 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_stack **stack)
{
	int	tmp;

	if (!stack || (*stack)->size < 2)
		return ;
	tmp = (*stack)->top->value;
	(*stack)->top->value = (*stack)->top->next->value;
	(*stack)->top->next->value = tmp;
}

void	ft_sa(t_stack **stack_a, t_list **cmndlist)
{
	ft_swap(stack_a);
	if (cmndlist)
		ft_lstadd_back(cmndlist, ft_lstnew(ft_strdup("sa")));
}

void	ft_sb(t_stack **stack_b, t_list **cmndlist)
{
	ft_swap(stack_b);
	if (cmndlist)
		ft_lstadd_back(cmndlist, ft_lstnew(ft_strdup("sb")));
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (cmndlist)
		ft_lstadd_back(cmndlist, ft_lstnew(ft_strdup("ss")));
}
