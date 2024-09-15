/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:17:49 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/14 11:59:41 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_init_check(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void ft_free_stack(t_stack **stack)
{
	t_node *cur_node;
	t_node *next_node;

	if (!stack || !(*stack))
		return ;
	cur_node = (*stack)->top;
	while (cur_node)
	{
		next_node = cur_node->next;
		free(cur_node);
		cur_node = next_node;
	}
	free(*stack);
	*stack = NULL;
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

int ft_fill_stack(t_stack **stack, int argc, char **argv)
{
	int i;
	int num;
	t_node *node;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi_pushswap(argv[i]);
		if (num == 0 && ft_strncmp(argv[i], "0", 1) != 0)
			return (0);
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
			return (0);
		node->value = num;
		node->next = (*stack)->top;
		(*stack)->top = node;
		if (!(*stack)->bottom)
			(*stack)->bottom = node;
		(*stack)->size++;
		i++;
	}
	return (1);
}
