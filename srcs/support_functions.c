/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:06:51 by yabukirento       #+#    #+#             */
/*   Updated: 2024/09/08 13:17:09 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi_pushswap(const char *str)
{
	int			i;
	int			sign;
	long long	ans;

	ans = 0;
	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i++] == '-')
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((ans > (INT64_MAX / 10))
			|| (ans == (INT64_MAX / 10) && (str[i] >= '8' && str[i] <= '9')))
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		ans *= 10;
		ans += str[i] - '0';
		i++;
	}
	return ((int)ans * sign);
}
