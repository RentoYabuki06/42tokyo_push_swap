/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:57:18 by yabukirento       #+#    #+#             */
/*   Updated: 2025/03/07 19:04:16 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_min(t_node *top)
{
	int		min;

	min = top->value;
	while (top)
	{
		if (top->value < min)
			min = top->value;
		top = top->next;
	}
	return (min);
}

int	ft_find_max(t_node *top)
{
	int		max;

	max = top->value;
	while (top)
	{
		if (top->value > max)
			max = top->value;
		top = top->next;
	}
	return (max);
}
