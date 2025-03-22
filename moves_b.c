/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:27:44 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/03/22 06:27:44 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **head_b)
{
	t_node	*tmp;
	t_node	*last;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	tmp = *head_b;
	last = *head_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	*head_b = (*head_b)->next;
	tmp->next = NULL;
	last->next = tmp;
	write(1, "rb\n", 3);
}

void	rrb(t_node **head_b)
{
	t_node	*tmp;
	t_node	*dup;

	if (*head_b == NULL)
		return ;
	dup = *head_b;
	while (dup->next->next != NULL)
		dup = dup->next;
	tmp = dup->next;
	dup->next = NULL;
	tmp->next = *head_b;
	*head_b = tmp;
	write(1, "rrb\n", 4);
}

void	sb(t_node *head_b)
{
	int	tmp;

	if (head_b == NULL)
		return ;
	tmp = head_b->nbr;
	head_b->nbr = head_b->next->nbr;
	head_b->next->nbr = tmp;
	tmp = head_b->index;
	head_b->index = head_b->next->index;
	head_b->next->index = tmp;
	write(1, "sb\n", 3);
}

void	pb(t_node **head_a, t_node **head_b)
{
	t_node	*tmp;

	if (*head_a == NULL)
		return ;
	tmp = *head_a;
	*head_a = (*head_a)->next;
	tmp->next = *head_b;
	*head_b = tmp;
	write(1, "pb\n", 3);
}
