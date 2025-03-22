/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:06:31 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/03/22 17:06:43 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *nptr)
{
	long	signe;
	long	result;

	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	signe = 1;
	result = 0;
	if (*nptr == '-')
		signe *= -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * signe);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s) + 1;
	dest = (char *)malloc(len * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, len);
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	frst;
	size_t	scnd;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
	{
		free(s1);
		return (ft_strdup(s1));
	}
	frst = ft_strlen(s1);
	scnd = ft_strlen(s2);
	new = (char *)malloc((frst + scnd + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, frst);
	ft_memcpy(new + frst, s2, scnd);
	new[frst + scnd] = '\0';
	free(s1);
	return (new);
}
