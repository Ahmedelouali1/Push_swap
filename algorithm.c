/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:27:18 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/03/22 06:32:54 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_list(t_node *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	get_totop_a(t_node **head, int position)
{
	int	i;
	int	size;

	if (position == 1)
		return ;
	if (*head == NULL)
		return ;
	i = 0;
	size = count_list(*head);
	if ((size / 2) >= position)
	{
		while (i < position - 1)
		{
			ra(head);
			i++;
		}
	}
	else
	{
		while (i < size - position + 1)
		{
			rra(head);
			i++;
		}
	}
}

void	get_totop_b(t_node **head, int position)
{
	int	i;
	int	size;

	if (position == 1)
		return ;
	if (*head == NULL)
		return ;
	i = 0;
	size = count_list(*head);
	if ((size / 2) >= position)
	{
		while (i < position - 1)
		{
			rb(head);
			i++;
		}
	}
	else
	{
		while (i < size - position + 1)
		{
			rrb(head);
			i++;
		}
	}
}

int	biggest_nbr(t_node *head)
{
	int	i;
	int	max;
	int	position;

	i = 1;
	max = 0;
	while (head)
	{
		if (max < head->index)
		{
			max = head->index;
			position = i;
		}
		head = head->next;
		i++;
	}
	return (position);
}

int	smalest_nbr(t_node *head)
{
	int	i;
	int	min;
	int	position;

	i = 1;
	min = head->index;
	while (head)
	{
		if (min > head->index)
		{
			min = head->index;
			position = i;
		}
		head = head->next;
		i++;
	}
	return (position);
}
