#include "push_swap.h"

void add_last(t_node **head, int nbr)
{
	t_node *new_node;
	t_node *tmp;

	tmp = *head;
	new_node = malloc(sizeof(t_node));
	new_node->next = NULL;
	new_node->nbr = nbr;

	if (*head == NULL)
	{
		*head= new_node;
		return;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;

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

void print_list(t_node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->nbr);
        head = head->next;
    }
}

int	main(int argc, char *argv[])
{
	t_node *head_a;
	t_node *head_b;
	int i;
	char *join;
	char **split;

	i = 1;
	head_a = NULL;
	head_b = NULL;
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
	i = 0;
	while(split[i])
	{
		add_last(&head_a, ft_atoi(split[i]));
		i++;
	}
	sa(head_a);
	sb(head_b);
	ra(head_a);
	rb(head_b);
	rr(head_a, head_b);
	print_list(head_a, head_b);
}
/*
int main()
{
	struct s_node *head;

	head = malloc(sizeof(struct s_node));
	head->nbr = 2003;
	head->next = malloc(sizeof(struct s_node));
	head->next->nbr = 12;
	head->next->next = malloc(sizeof(struct s_node));
	head->next->next->nbr = 12;
	head->next->next->next = malloc(sizeof(struct s_node));
	head->next->next->next->nbr = 21;
	head->next->next->next->next = NULL;
	
	struct s_node *tmp;

	tmp = head;
	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
}*/