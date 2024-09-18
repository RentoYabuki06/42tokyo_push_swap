/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:06:51 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/18 19:38:11 by ryabuki          ###   ########.fr       */
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

int ft_fill_stack(t_stack **stack, int argc, char **argv, bool issplit)
{
    int     i;
    int     num;
    t_node  *node;
	(void)	argc;

    i = 1; // 後で調整します
    if (issplit)
        i = 0; // `ft_split` 後の引数配列はインデックス0から始まる

    while (argv[i])
    {
        num = ft_atoi_pushswap(argv[i]);
        if (num == 0 && !ft_is_zero(argv[i]))
        {
            ft_printf("---- atoi failed!  -----\n"); // テスト用
            return (0);
        }
        if (ft_check_duplicates(stack, num))
        {
            ft_printf("---- duplicated!  -----\n"); // テスト用
            return (0);
        }
        node = (t_node *)malloc(sizeof(t_node));
        if (!node)
        {
            ft_printf("---- node malloc failed!  -----\n"); // テスト用
            return (0);
        }
        node->value = num;
        node->next = NULL;
        if ((*stack)->top == NULL)
        {
            // スタックが空の場合
            (*stack)->top = node;
            (*stack)->bottom = node;
        }
        else
        {
            // スタックが空でない場合
            (*stack)->bottom->next = node;
            (*stack)->bottom = node;
        }
        (*stack)->size++;
        i++;
    }
    return (1);
}
