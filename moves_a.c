#include "push_swap.h"

void ra(t_node **head_a)
{
    t_node *tmp;
    t_node *last;

    if (*head_a == NULL || (*head_a)->next == NULL)
        return ;
    tmp = *head_a;
    last = *head_a;
    while(last->next != NULL)
    {
        last = last->next;
    }
    *head_a = (*head_a)->next;
    tmp->next= NULL;
    last->next = tmp;
    write(1, "ra\n", 3);
}

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

void sa(t_node *head_a)
{
    int tmp;

    if (head_a == NULL)
        return ;
    tmp = head_a->nbr;
    head_a->nbr = head_a->next->nbr;
    head_a->next->nbr = tmp;
    tmp = head_a->index;
    head_a->index = head_a->next->index;
    head_a->next->index = tmp;
    write(1, "sa\n", 3);
}