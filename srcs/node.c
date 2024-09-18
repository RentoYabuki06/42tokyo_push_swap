/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:57:35 by ryabuki           #+#    #+#             */
/*   Updated: 2024/09/18 19:37:02 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_stack **stack)
{
	int		size;
	t_node	*tmp;

	size = (*stack)->size;
	if (size == 0)
	{
		ft_printf("note : This stack is empty!\n");
		return ;
	}
	ft_printf("-----  Printing Stack (Top to Down)  -------\n");
	tmp = ((*stack)->top);
	ft_printf("[%d]\n", tmp->value);
	while (tmp->next)
	{
		tmp = tmp->next;
		ft_printf("[%d]\n", tmp->value);
	}
	ft_printf("--------  Finish!!  -------\n");
}

void	ft_print_argv(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
	{
		ft_printf("[%d] of argv is [%s]\n" , i, argv[i]);
		i++;
	}
	return ;
}