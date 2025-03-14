#include "push_swap.h"

void pa(t_node **head_a, t_node **head_b)
{
    t_node *tmp;

    if(*head_b == NULL)
        return ;
    tmp = *head_b;
    *head_b = (*head_b)->next;
    tmp->next = *head_a;
    *head_a = tmp;
    write(1, "pa\n", 3);
    
}