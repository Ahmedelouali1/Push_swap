#include "push_swap.h"

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