/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:27:30 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/03/24 05:31:49 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_orno(char *str)
{
	int		i;
	long	nb;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	if (i > 12)
		return (0);
	nb = ft_atoi(str);
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}
