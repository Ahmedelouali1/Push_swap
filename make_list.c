/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:27:35 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/03/29 06:47:20 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_list(t_node **head_a, char *join, int i)
{
	char	**split;

	split = ft_split(join, ' ');
	free(join);
	if (!split)
		return (0);
	if (check_args(split) == 0)
		return (0);
	while (split[i])
	{
		if (add_last(head_a, ft_atoi(split[i++])) == 0)
		{
			free_list(*head_a);
			delete(split);
			return (0);
		}
	}
	delete (split);
	if (list_indexing(*head_a) == 1)
	{
		write(2, "Error\n", 6);
		free_list(*head_a);
		return (0);
	}
	return (1);
}
