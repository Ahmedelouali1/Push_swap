#include "push_swap.h"

void rb(t_node **head_b)
{
    t_node *tmp;
    t_node *last;

    if (*head_b == NULL)
        return ;
    tmp = *head_b;
    *head_b = (*head_b)->next;
    tmp->next= NULL;
    last = *head_b;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = tmp;
    write(1, "rb\n", 3);
}