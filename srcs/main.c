/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:26:06 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/19 23:48:08 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack **stack)
{
	t_node	*cur_node;

	if (!(*stack) || !(*stack)->top)
		return (1);
	cur_node = (*stack)->top;
	while (cur_node->next)
	{
		if (cur_node->value > cur_node->next->value)
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}

static void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_is_sorted(stack_a))
		return ;
	else if ((*stack_a)->size == 2)
	{
		if ((*stack_a)->top->value > (*stack_a)->top->next->value)
			ft_sa(stack_a);
	}
	else if ((*stack_a)->size == 3)
		ft_sort_three(stack_a, 0, 0, 0);
	else if ((*stack_a)->size == 4)
		ft_sort_four(stack_a, stack_b);
	else if ((*stack_a)->size == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort_large(stack_a, stack_b);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	bool	issplit;

	issplit = false;
	if (argc < 2)
	{
		// ft_printf("---- argc is needed! -----\n"); // test
		return (0);
	}
	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 1;
		issplit = true;
		while (argv[argc - 1])
			argc++;
		// ft_printf("---- split done! argc is [%d] , stack size [%d][%d] -----\n", argc, stack_a->size, stack_b->size); // test
	}
	// ft_print_argv(argv); // teset
	if (argc == 2)
	{
		// ft_printf("---- more argc is wanted!  -----\n"); // test
		return (0);
	}
	if (!ft_fill_stack(&stack_a, argc, argv, issplit))
	{
		ft_printf("Error\n");
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
		exit(EXIT_FAILURE);
	}
	// ft_printf("---->>>>> before sort, argc is [%d] , stack size [%d][%d]  >>>>>>-----\n", argc, stack_a->size, stack_b->size); // test
	// ft_print_stack(&stack_a);
	// ft_print_stack(&stack_b);
	ft_push_swap(&stack_a, &stack_b);
	// ft_printf("-----\n-----\n-----\n-----\n-----\n-----\n"); // test
	// ft_printf("---->>>>> after sort, argc is [%d] , stack size [%d][%d]  >>>>>>>-----\n", argc, stack_a->size, stack_b->size); // test
	// ft_print_stack(&stack_a);
	// ft_print_stack(&stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
