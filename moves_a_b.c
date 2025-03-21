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

void ss(t_node *head_a, t_node *head_b)
{
    int tmp;
    
    if (head_a != NULL)
    {
        tmp = head_a->nbr;
        head_a->nbr = head_a->next->nbr;
        head_a->next->nbr = tmp;
    }
    if (head_b != NULL)
    {
        tmp = head_b->nbr;
        head_b->nbr = head_b->next->nbr;
        head_b->next->nbr = tmp;
    }
    write(1, "ss\n", 3);
}
