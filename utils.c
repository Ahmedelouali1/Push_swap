/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 06:28:03 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/03/22 17:12:36 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**delete(char **alloc)
{
	int	a;

	a = 0;
	while (alloc[a])
	{
		free(alloc[a]);
		a++;
	}
	free(alloc);
	return (NULL);
}

int	ft_count(char *s, char c)
{
	size_t	i;
	size_t	contain_c;

	i = 0;
	contain_c = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			contain_c++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (contain_c);
}

char	*word_traitement(char *s, char c)
{
	char	*temp;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	**ft_split(char *s, char c)
{
	int		b;
	char	**all;

	b = 0;
	all = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!all)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			all[b] = word_traitement(s, c);
			if (!all[b])
				return (delete (all));
			b++;
			while (*s && *s != c)
				s++;
		}
	}
	all[b] = NULL;
	return (all);
}
