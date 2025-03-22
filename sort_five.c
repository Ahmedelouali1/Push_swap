/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:33:25 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/03/22 06:34:38 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *head)
{
	while (head->next != NULL)
	{
		if (head->nbr > head->next->nbr)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort_two(t_node *head)
{
	if (head->nbr > head->next->nbr)
		sa(head);
}

void	sort_three(t_node **head_a)
{
	if (biggest_nbr(*head_a) == 1)
		ra(head_a);
	else if (biggest_nbr(*head_a) == 2)
		rra(head_a);
	if ((*head_a)->nbr > (*head_a)->next->nbr)
		sa(*head_a);
}

void	sort_four(t_node **head_a, t_node **head_b)
{
	get_totop_a(head_a, smalest_nbr(*head_a));
	pb(head_a, head_b);
	sort_three(head_a);
	pa(head_a, head_b);
}

void	sort_five(t_node **head_a, t_node **head_b)
{
	get_totop_a(head_a, smalest_nbr(*head_a));
	pb(head_a, head_b);
	sort_four(head_a, head_b);
	pa(head_a, head_b);
}
