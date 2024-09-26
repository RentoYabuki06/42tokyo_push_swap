/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:17:49 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/26 15:51:26 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_free_stack(t_stack **stack)
{
	t_node	*cur_node;
	t_node	*next_node;

	if (!stack || !(*stack))
		return ;
	if (!(*stack)->top)
	{
		free(*stack);
		*stack = NULL;
		return ;
	}
	cur_node = (*stack)->top;
	while (cur_node)
	{
		next_node = cur_node->next;
		free(cur_node);
		cur_node = next_node;
	}
	if (*stack)
		free(*stack);
	*stack = NULL;
}

// static void ft_free_split(char **split)
// {
// 	int	i;

// 	i = 0;
// 	while (split[i])
// 	{
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// }

static void	ft_free_lst(t_list **lst)
{
	t_list	*plst;
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	plst = *lst;
	while (plst)
	{
		tmp = plst->next;
		free(plst);
		plst = tmp;
	}
	*lst = NULL;
}


void	ft_free_all(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	ft_free_stack(stack_a);
	ft_printf("after free : stack a\n");
	ft_free_stack(stack_b);
	ft_printf("after free : stack b\n");
	ft_free_lst(cmndlist);
	ft_printf("after free : cmndlist\n");
	// ft_free_split(split);
	// ft_printf("after free : split\n");
}
