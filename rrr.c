#include "push_swap.h"

void rrr(t_node **head_a, t_node **head_b)
{
    t_node *tmp;
    t_node *dup;

    if (*head_a != NULL)
    {
        dup = *head_a;
        while (dup->next->next != NULL)
            dup = dup->next;
        tmp = dup->next;
        dup->next = NULL;
        tmp->next = *head_a;
        *head_a = tmp;   
    }   
    if (*head_b != NULL)
    {
        dup = *head_b;
        while (dup->next->next != NULL)
            dup = dup->next;
        tmp = dup->next;
        dup->next = NULL;
        tmp->next = *head_b;
        *head_b = tmp;
    }
    write(1, "rrr\n", 4);
}