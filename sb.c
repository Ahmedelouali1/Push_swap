#include "push_swap.h"

void sb(t_node *head_b)
{
    int tmp;

    if (head_b == NULL)
        return ;
    tmp = head_b->nbr;
    head_b->nbr = head_b->next->nbr;
    head_b->next->nbr = tmp;
    write(1, "sb\n", 3);
}