#include "push_swap.h"

void rra(t_node **head_a)
{
    t_node *tmp;
    t_node *dup;

    if (*head_a == NULL)
        return ;
    dup = *head_a;
    while (dup->next->next != NULL)
        dup = dup->next;
    tmp = dup->next;
    dup->next = NULL;
    tmp->next = *head_a;
    *head_a = tmp;
    write(1, "rra\n", 4);
}