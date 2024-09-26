/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:26:06 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/26 15:51:11 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	ft_push_swap(t_stack **stack_a, \
	t_stack **stack_b, t_list **cmndlist, t_node *top)
{
	t_list	*tmp;

	if (ft_is_sorted(stack_a))
		return ;
	else if ((*stack_a)->size == 2 && top->value > top->next->value)
		ft_sa(stack_a, cmndlist);
	else if ((*stack_a)->size == 2)
		return ;
	else if ((*stack_a)->size == 3)
		ft_sort_three(stack_a, top->value, top->next->value, cmndlist);
	else if ((*stack_a)->size == 4)
		ft_sort_four(stack_a, stack_b, cmndlist);
	else if ((*stack_a)->size == 5)
		ft_sort_five(stack_a, stack_b, cmndlist);
	else
		ft_sort_large(stack_a, stack_b, cmndlist);
	tmp = (*cmndlist)->next;
	while (tmp && tmp->content && cmndlist)
	{
		ft_putstr_fd(tmp->content, 1);
		ft_putstr_fd("\n", 1);
		tmp = tmp->next;
	}
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

static void	ft_init(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	*stack_a = ft_init_stack();
	*stack_b = ft_init_stack();
	*cmndlist = ft_lstnew("start");
	if (!cmndlist)
		ft_error(stack_a, stack_b, cmndlist);
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
		ft_error(&stack_a, &stack_b, &cmndlist);
	if (ft_issplit(argv[1]))
		split = ft_split(argv[1], ' ');
	else
		split = argv + 1;
	if (argc == 2 && !ft_issplit(argv[1]))
	{
		argc = ft_atoi_ps(split[0], &stack_a, &stack_b, &cmndlist);
		ft_free_all(&stack_a, &stack_b, &cmndlist);
		return (0);
	}
	ft_printf("before fill\n");
	ft_fill(&stack_a, &stack_b, split, &cmndlist);
	ft_printf("after fill\n");
	ft_push_swap(&stack_a, &stack_b, &cmndlist, stack_a->top);
	ft_printf("after push_swap\n");
	ft_free_all(&stack_a, &stack_b, &cmndlist);
	return (0);
}


__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}
