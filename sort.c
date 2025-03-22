/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:28:00 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/03/22 17:06:03 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_node **head_a, t_node **head_b)
{
	int	size;

	size = count_list(*head_a);
	if (size == 2)
		sort_two(*head_a);
	if (size == 3)
		sort_three(head_a);
	if (size == 4)
		sort_four(head_a, head_b);
	if (size == 5)
		sort_five(head_a, head_b);
	if (size > 5)
		big_sort(head_a, head_b);
	free_list(*head_a);
}
