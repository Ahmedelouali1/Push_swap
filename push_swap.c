#include "push_swap.h"

int add_last(t_node **head, int nbr)
{
	t_node *new_node;
	t_node *tmp;

	tmp = *head;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->next = NULL;
	new_node->nbr = nbr;
	if (*head == NULL)
	{
		*head= new_node;
		return (1);
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
	return (1);
}
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

int list_indexing(t_node *head)
{
	t_node *dup;
	t_node *tmp;

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
	return(0);
}
int check_args(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		if (valid_orno(split[i]) == 0)
		{
			write(2, "Error\n", 6);
			delete(split);
			return (0);
		}
		i++;
	}
	return (1);
}

int make_list(t_node **head_a, char *join, int i)
{
	char **split;

	split = ft_split(join, ' ');
	free(join);
	if (!split)
		return (0);
	if(check_args(split) == 0)
		return(0);
	while(split[i])
	{
		if (add_last(head_a, ft_atoi(split[i++])) == 0)
		{
			delete(split);
			return(0);
		}
	}
	delete(split);
	if (list_indexing(*head_a) == 1)
	{
		write(2, "Error\n", 6);
		free_list(*head_a);
		return (0);
	}
	return (1);
}
void free_list(t_node *head_a)
{
	t_node *tmp;

	while (head_a)
	{
		tmp = head_a->next;
		free(head_a);
		head_a = tmp;
	}
}

void sort(t_node **head_a, t_node **head_b)
{
	int size;

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

int	main(int argc, char *argv[])
{
	t_node *head_a;
	t_node *head_b;
	int i;
	char *join;

	i = 1;
	head_a = NULL;
	head_b = NULL;
	join = NULL;
	if (argc == 1)
		return (0);
	while (argv[i])
	{
		join = ft_strjoin(join, argv[i++]);
		if (!join)
			return (0);
		join = ft_strjoin(join, " ");
		if (!join)
			return (0);
	}
	if (make_list(&head_a,join, 0) == 0)
		return (0);
	if (is_sorted(head_a) == 1)
		return (0);
	sort(&head_a, &head_b);
}
