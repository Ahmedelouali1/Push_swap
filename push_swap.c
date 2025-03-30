/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:27:47 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/03/29 17:18:27 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_last(t_node **head, int nbr)
{
	t_node	*new_node;
	t_node	*tmp;

	tmp = *head;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->next = NULL;
	new_node->nbr = nbr;
	if (*head == NULL)
	{
		*head = new_node;
		return (1);
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
	return (1);
}

int	list_indexing(t_node *head)
{
	t_node	*dup;
	t_node	*tmp;

	tmp = head;
	dup = head;
	while (head)
	{
		dup = tmp;
		head->index = 1;
		while (dup)
		{
			if (head != dup)
			{
				if (dup->nbr < head->nbr)
					head->index += 1;
				if (dup->nbr == head->nbr)
					return (1);
			}
			dup = dup->next;
		}
		head = head->next;
	}
	return (0);
}

int	check_args(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (valid_orno(split[i]) == 0)
		{
			write(2, "Error\n", 6);
			delete (split);
			return (0);
		}
		i++;
	}
	return (1);
}

void	free_list(t_node *head_a)
{
	t_node	*tmp;

	while (head_a)
	{
		tmp = head_a->next;
		free(head_a);
		head_a = tmp;
	}
}

int	main(int argc, char *argv[])
{
	t_node	*head_a;
	t_node	*head_b;
	int		i;
	char	*join;

	i = 1;
	head_a = NULL;
	head_b = NULL;
	join = NULL;
	if (argc == 1)
		return (0);
	if (is_only_space(argv[1]))
		return (write_error(), 0);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (ft_error(join));
		join = ft_strjoin(join, argv[i++]);
		if (!join)
			return (0);
		join = ft_strjoin(join, " ");
		if (!join)
			return (0);
	}
	start_sort(&head_a, &head_b, join);
}
