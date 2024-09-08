/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:26:06 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/08 10:34:29 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void ft_free_stack(t_stack **stack)
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

static t_stack	*ft_init_stack(void)
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

static int ft_fill_stack(t_stack **stack, int argc, char **argv)
{
	int i;
	int num;
	t_node *node;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num == 0 && ft_strcmp(argv[i], "0") != 0)
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

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (0);
	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	if (!ft_fill_stack(&stack_a, argc, argv))
		return (0);
	ft_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
