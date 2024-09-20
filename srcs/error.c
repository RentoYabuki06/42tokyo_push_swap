/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:02:02 by ryabuki           #+#    #+#             */
/*   Updated: 2024/09/20 14:02:27 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(t_stack **stack_a, t_stack **stack_b, t_list **cmndlist)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_all(stack_a, stack_b, cmndlist);
	exit(1);
}
