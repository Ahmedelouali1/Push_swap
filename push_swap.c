#include "push_swap.h"

int	valid_orno(char *str)
{
	int		i;
	long	nb;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	if (i > 12)
		return (0);
	nb = ft_atoi(str);
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	int i;
	char *join;
	char **split;

	i = 1;
	join = NULL;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		join = ft_strjoin(join, argv[i]);
		join = ft_strjoin(join, " ");
		i++;
	}
	split = ft_split(join, ' ');
	i = 0;
	while (split[i])
	{
		if (valid_orno(split[i]) == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	// printf("%s\n", join);
}