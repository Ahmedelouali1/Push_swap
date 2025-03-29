/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 05:52:09 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/03/29 06:57:43 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(char *join)
{
	write(2, "Error\n", 6);
	free(join);
	return (0);
}

int	start_sort(t_node **head_a, t_node **head_b, char *join)
{
	if (make_list(head_a, join, 0) == 0)
		return (0);
	if (is_sorted(*head_a) == 1)
	{
		free_list(*head_a);
		return (0);
	}
	sort(head_a, head_b);
	return (1);
}
