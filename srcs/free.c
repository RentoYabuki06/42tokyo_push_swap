/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:17:49 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/26 20:19:50 by yabukirento      ###   ########.fr       */
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

void ft_free_split(char **split)
{
	int i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}


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
		if (plst->content)
			free(plst->content);
		free(plst);
		plst = tmp;
	}
	*lst = NULL;
}


void	ft_free_all(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist, char **split)
{
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	ft_free_lst(cmndlist);
	ft_free_split(split);
}
