/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:02:02 by ryabuki           #+#    #+#             */
/*   Updated: 2024/09/26 21:32:49 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(t_stack **stack_a, t_stack **stack_b, char **split)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_all(stack_a, stack_b, split);
	exit(EXIT_FAILURE);
}
