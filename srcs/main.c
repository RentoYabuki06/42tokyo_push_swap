/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:26:06 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/26 20:21:15 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_print_cmnds(t_list **cmndlist)
{
	t_list	*tmp;

	tmp = (*cmndlist)->next;
	while (tmp)
	{
		if (tmp->content)
		{
			ft_putstr_fd(tmp->content, 1);
			ft_putstr_fd("\n", 1);
		}
		tmp = tmp->next;
	}
}


static void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	int		size;
	t_node	*top;

	size = (*stack_a)->size;
	top = (*stack_a)->top;
	if (ft_is_sorted(stack_a))
		return ;
	else if (size == 2 && top->value > top->next->value)
		ft_sa(stack_a, cmndlist);
	else if (size == 2)
		return ;
	else if (size == 3)
		ft_sort_three(stack_a, top->value, top->next->value, cmndlist);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b, cmndlist);
	else if (size == 5)
		ft_sort_five(stack_a, stack_b, cmndlist);
	else
		ft_sort_quick_a(stack_a, stack_b, size, cmndlist);
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
	t_list	*cmndlist;
	char	**split;

	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	ft_init(&stack_a, &stack_b, &cmndlist);
	if (ft_issplit(argv[1]) && argc != 2)
		ft_error(&stack_a, &stack_b, &cmndlist, NULL);
	if (ft_issplit(argv[1]))
		split = ft_split(argv[1], ' ');
	else
		split = argv + 1;
	if (argc == 2 && !ft_issplit(argv[1]) && ft_atoi_ps(split[0]) == 1 && !ft_is_one(split[0]))
	{
		ft_free_all(&stack_a, &stack_b, &cmndlist, NULL);
		return (0);
	}
	ft_printf("before fill\n");
	if (ft_fill(&stack_a, split))
	{
		if (ft_issplit(argv[1]))
			ft_free_split(split);
		ft_free_all(&stack_a, &stack_b, &cmndlist, NULL);
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
	ft_push_swap(&stack_a, &stack_b, &cmndlist);
	ft_print_cmnds(&cmndlist);
	ft_printf(">>>>>>>>>>>> after push_swap\n");
	ft_printf("-----  stack a  ----\n");
	ft_print_stack(stack_a);
	ft_printf("-----  stack b  ----\n");
	ft_print_stack(stack_b);
	ft_free_all(&stack_a, &stack_b, &cmndlist, NULL);
	return (0);
}


__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}
