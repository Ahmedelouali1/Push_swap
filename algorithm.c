#include "push_swap.h"

int is_sorted(t_node *head)
{
    while (head->next != NULL)
    {
        if (head->nbr >head->next->nbr)
            return (0);
        head = head->next;
    }
    return (1);
}

void sort_two(t_node *head)
{
    if (head->nbr > head->next->nbr)
        sa(head);
}

void sort_three(t_node *head_a, t_node *head_b)
{
    if (is_sorted(head_a) == 0)
    {
        
    }
}
// check for dup