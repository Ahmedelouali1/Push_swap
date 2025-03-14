#include "push_swap.h"

void sa(t_node *head_a)
{
    int tmp;

    if (head_a == NULL)
        return ;
    tmp = head_a->nbr;
    head_a->nbr = head_a->next->nbr;
    head_a->next->nbr = tmp;
    write(1, "sa\n", 3);
}