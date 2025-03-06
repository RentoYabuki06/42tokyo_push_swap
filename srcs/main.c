/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:26:06 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/06 17:13:22 by yabukirento      ###   ########.fr       */
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

static bool	ft_is_return(int argc, char **argv, t_stack **stack_a, char **split)
{
	if (argc == 2 && !ft_issplit(argv[1]) \
		&& ft_atoi_ps(split[0]) == 1 && !ft_is_one(split[0]))
		return (true);
	if (ft_fill(stack_a, split))
	{
		if (ft_issplit(argv[1]))
			ft_free_split(split);
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split;

	if (argc == 1 || argv[1][0] == '\0')
		return (EXIT_SUCCESS);
	if (argc == 1 || argv[1][0] == '\0')
		return (EXIT_SUCCESS);
	ft_init(&stack_a, &stack_b);
	if (ft_issplit(argv[1]) && argc != 2)
		ft_error(&stack_a, &stack_b, NULL);
	if (ft_issplit(argv[1]))
		split = ft_split(argv[1], ' ');
	else
		split = argv + 1;
	if (ft_is_return(argc, argv, &stack_a, split))
		ft_error(&stack_a, &stack_b, split);
	if (ft_issplit(argv[1]))
		ft_free_split(split);
	ft_push_swap(&stack_a, &stack_b);
	ft_free_all(&stack_a, &stack_b, NULL);
	return (EXIT_SUCCESS);
}
