#include "push_swap.h"

void ra(t_node **head_a)
{
    t_node *tmp;
    t_node *last;

    if (*head_a == NULL)
        return ;
    tmp = *head_a;
    *head_a = (*head_a)->next;
    tmp->next= NULL;
    last = *head_a;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = tmp;
    write(1, "ra\n", 3);
}