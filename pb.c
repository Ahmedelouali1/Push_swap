#include "push_swap.h"

void pb(t_node **head_a, t_node **head_b)
{
    t_node *tmp;

    if(*head_a == NULL)
        return ;
    tmp = *head_a;
    *head_a = (*head_a)->next;
    tmp->next = *head_b;
    *head_b = tmp;
    write(1, "pb\n", 3);
}