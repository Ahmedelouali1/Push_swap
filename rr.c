#include "push_swap.h"

void rr(t_node **head_a, t_node **head_b)
{
    t_node *tmp;
    t_node *last;

    if (*head_a != NULL)
    {
        tmp = *head_a;
        *head_a = (*head_a)->next;
        tmp->next= NULL;
        last = *head_a;
        while(last->next != NULL)
            last = last->next;
        last->next = tmp;
    }
    if (*head_b != NULL)
    {
        tmp = *head_b;
        *head_b = (*head_b)->next;
        tmp->next= NULL;
        last = *head_b;
        while(last->next != NULL)
            last = last->next;
        last->next = tmp;
    }
    write(1, "rr\n", 3);   
}