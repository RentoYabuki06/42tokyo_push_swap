/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:26:06 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/26 21:32:24 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	t_node	*top;

	size = (*stack_a)->size;
	top = (*stack_a)->top;
	if (ft_is_sorted(stack_a))
		return ;
	else if (size == 2 && top->value > top->next->value)
		ft_sa(stack_a);
	else if (size == 2)
		return ;
	else if (size == 3)
		ft_sort_three(stack_a, top->value, top->next->value);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (size == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort_quick_a(stack_a, stack_b, size);
}

static bool	ft_issplit(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' && str[i])
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
		i++;
	if (!ft_isdigit(str[i]))
		return (false);
	while (ft_isdigit(str[i]) && str[i])
		i++;
	while (str[i] == ' ' && str[i])
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
		i++;
	if (ft_isdigit(str[i]) && str[i])
		return (true);
	return (false);
}

void	ft_print_stack(t_stack *stack) // testよう
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
	{
		ft_printf("Stack is empty\n");
		return;
	}
	
	current = stack->top;
	while (current != NULL)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}


int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split;

	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	ft_init(&stack_a, &stack_b);
	if (ft_issplit(argv[1]) && argc != 2)
		ft_error(&stack_a, &stack_b, NULL);
	if (ft_issplit(argv[1]))
		split = ft_split(argv[1], ' ');
	else
		split = argv + 1;
	if (argc == 2 && !ft_issplit(argv[1]) && ft_atoi_ps(split[0]) == 1 && !ft_is_one(split[0]))
	{
		ft_free_all(&stack_a, &stack_b, NULL);
		return (0);
	}
	ft_printf("before fill\n");
	if (ft_fill(&stack_a, split))
	{
		if (ft_issplit(argv[1]))
			ft_free_split(split);
		ft_free_all(&stack_a, &stack_b, NULL);
		ft_printf("fill failed\n");
		return (0);
	}
	ft_printf("before free split\n");
	if (ft_issplit(argv[1]))
		ft_free_split(split);
	ft_printf(">>>>>>>>>>> before push_swap\n");
	ft_printf("-----  stack a  ----\n");
	ft_print_stack(stack_a);
	ft_printf("-----  stack b  ----\n");
	ft_print_stack(stack_b);
	ft_printf("-----  start operation!  ----\n");
	ft_push_swap(&stack_a, &stack_b);
	ft_printf(">>>>>>>>>>>> after push_swap\n");
	ft_printf("-----  stack a  ----\n");
	ft_print_stack(stack_a);
	ft_printf("-----  stack b  ----\n");
	ft_print_stack(stack_b);
	ft_free_all(&stack_a, &stack_b, NULL);
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}
