#include "push_swap.h"

long	ft_atoi(char *nptr)
{
	long		signe;
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

char **delete (char **alloc)
{
	int	a;

	a = 0;
	while (alloc[a])
	{
		free(alloc);
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
	int b;
	char **all;

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