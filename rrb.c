#include "push_swap.h"

void rrb(t_node **head_b)
{
    t_node *tmp;
    t_node *dup;

    if (*head_b == NULL)
        return ;
    dup = *head_b;
    while (dup->next->next != NULL)
        dup = dup->next;
    tmp = dup->next;
    dup->next = NULL;
    tmp->next = *head_b;
    *head_b = tmp;
    write(1, "rrb\n", 4);
}