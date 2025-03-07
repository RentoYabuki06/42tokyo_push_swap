/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:06:51 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/07 19:07:19 by yabukirento      ###   ########.fr       */
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

int	ft_atoi_ps(char *s)
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
		return (EXIT_FAILURE);
	while (*s >= '0' && *s <= '9')
		ans = (ans * 10) + (*(s++) - 48);
	if (ans > 2147483648)
		return (EXIT_FAILURE);
	while (*s == ' ')
		s++;
	if (*s != '\0')
		return (EXIT_FAILURE);
	if ((sign * ans) > 2147483647 || (sign * ans) < -2147483648)
		return (EXIT_FAILURE);
	return ((int)(ans * sign));
}

bool	ft_is_one(char *s)
{
	while (ft_is_space(*s))
		s++;
	if (*s == '-' || *s == '+')
		s++;
	if (*s != '1')
		return (false);
	s++;
	if (*s != '\0')
		return (false);
	return (true);
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

int	ft_fill(t_stack **stack_a, char **split)
{
	int		i;
	int		num;
	t_node	*node;

	i = 0;
	while (split[i])
	{
		num = ft_atoi_ps(split[i]);
		if ((num == 1 && !ft_is_one(split[i])) \
			|| ft_check_duplicates(stack_a, num))
			return (EXIT_FAILURE);
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
			return (EXIT_FAILURE);
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
	return (EXIT_SUCCESS);
}
