#include "push_swap.h"

void push_chunk(t_node **head_a, t_node **head_b, int chunk_size, int step)
{
    int position;
    t_node *tmp;

    tmp = *head_a;
    position = 1;
    while (tmp)
    {
        if (tmp->index <= chunk_size)
        {
            get_totop_a(head_a, position);
            pb(head_a, head_b);
            if ((*head_b)->index <= (chunk_size - (step / 2)))
                rb(head_b);
            // put_stack(*head_a, *head_b);
            tmp = *head_a;
            position = 1;
        }
        else
        {
            tmp = tmp->next;
            position++;
        }
    }
}

void big_sort(t_node **head_a, t_node **head_b)
{
    int size;
    int chunk_size;
    int step;

    size = count_list(*head_a);
    if (size <= 100)
        chunk_size = size / 4;
    else
        chunk_size = size / 9;
    step = chunk_size;
    while(*head_a != NULL)
    {
        push_chunk(head_a, head_b, chunk_size, step);
        chunk_size += step;
    }
    while (*head_b != NULL)
    {
        get_totop_b(head_b, biggest_nbr(*head_b));
        pa(head_a, head_b);
    }
}
