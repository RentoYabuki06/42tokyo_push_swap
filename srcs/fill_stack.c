/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:06:51 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/15 16:38:59 by ryabuki          ###   ########.fr       */
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

static int	ft_atoi_pushswap(char *str)
{
	int			sign;
	long long	ans;

	ans = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		if (!ft_isdigit(*str))
			return (0);
		ans = (ans * 10) + (*str - 48);
		str++;
	}
	if ((sign * ans) > 2147483647 || (sign * ans) < -2147483648)
		return (0);
	return ((int)(ans * sign));
}

static bool	ft_is_zero(const char *str)
{
	int	i = 0;

	while (ft_is_space(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i])
		i++;
	while (str[i] == '0')
		i++;
	if (str[i] == '\0')
		return (true);
	return (false);
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

int ft_fill_stack(t_stack **stack, int argc, char **argv)
{
	int		i;
	int		num;
	t_node	*node;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi_pushswap(argv[i]);
		if (num == 0 && !ft_is_zero(argv[i]))
		{
			ft_printf("---- atoi failed!  -----\n"); // test
			return (0);
		}
		if (ft_check_duplicates(stack, num))
		{
			ft_printf("---- duplicated!  -----\n"); // test
			return (0);
		}
		node = (t_node *)malloc(sizeof(t_node));
		if (!node)
		{
			ft_printf("---- node malloc failed!  -----\n"); // test
			return (0);
		}
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
