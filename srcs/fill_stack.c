/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:06:51 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/20 17:32:08 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	ft_is_space(char c)
{
	char	*str;

	str = "\t\n\v\f\r ";
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

int	ft_atoi_ps(char *s, t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	int			sign;
	long long	ans;

	ans = 0;
	sign = 1;
	while (ft_is_space(*s))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	if (!*s || ft_isdigit(*s) == false)
		ft_error(stack_a, stack_b, cmndlist);
	while (*s >= '0' && *s <= '9')
		ans = (ans * 10) + (*(s++) - 48);
	if (ans > 2147483648)
		ft_error(stack_a, stack_b, cmndlist);
	while (*s == ' ')
		s++;
	if (*s != '\0')
		ft_error(stack_a, stack_b, cmndlist);
	if ((sign * ans) > 2147483647 || (sign * ans) < -2147483648)
		ft_error(stack_a, stack_b, cmndlist);
	return ((int)(ans * sign));
}

static bool	ft_check_duplicates(t_stack **stack, int num)
{
	t_node	*tmp;

	tmp = (*stack)->top;
	while (tmp)
	{
		if (tmp->value == num)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	ft_fill(t_stack **stack_a, t_stack **stack_b, char **argv, t_list **cmd)
{
	int		i;
	int		num;
	t_node	*node;

	i = 0;
	while (argv[i])
	{
		num = ft_atoi_ps(argv[i], stack_a, stack_b, cmd);
		if (ft_check_duplicates(stack_a, num))
			ft_error(stack_a, stack_b, cmd);
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
			ft_error(stack_a, stack_b, cmd);
		node->value = num;
		node->next = NULL;
		if ((*stack_a)->top == NULL)
			(*stack_a)->top = node;
		else
			(*stack_a)->bottom->next = node;
		(*stack_a)->bottom = node;
		(*stack_a)->size++;
		i++;
	}
}
