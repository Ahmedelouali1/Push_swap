#include "push_swap.h"

int count_list(t_node *head)
{
    int i;

    i = 0;
    while (head)
    {
        head = head->next;
        i++;
    }
    return (i);
}
void get_totop_a(t_node **head, int position)
{
    int i;
    int size;

    if (position == 1)
        return ;
    if (*head == NULL)
        return ;
    i = 0;
    size = count_list(*head);
    if ((size / 2) >= position)
    {
        while(i < position - 1)
        {
            ra(head);
            i++;
        }  
    }
    else
    {
        while(i < size - position + 1)
        {
            rra(head);
            i++;
        }
    } 
}

void get_totop_b(t_node **head, int position)
{
    int i;
    int size;

    if (position == 1)
        return ;
    if (*head == NULL)
        return ;
    i = 0;
    size = count_list(*head);
    if ((size / 2) >= position)
    {
        while(i < position - 1)
        {
            rb(head);
            i++;
        }  
    }
    else
    {
        while(i < size - position + 1)
        {
            rrb(head);
            i++;
        }
    } 
}

int biggest_nbr(t_node *head)
{
    int i;
    int max;
    int position;

    i = 1;
    max = 0;
    while(head)
    {
        if (max < head->index)
        {
            max = head->index;
            position = i;
        }
        head = head->next;
        i++;
    }
    return (position);
}
int smalest_nbr(t_node *head)
{
    int i;
    int min;
    int position;

    i = 1;
    min = head->index;
    while(head)
    {
        if (min > head->index)
        {
            min = head->index;
            position = i;
        }
        head = head->next;
        i++; 
    }
    return (position);
}

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

void sort_three(t_node **head_a)
{
    if (biggest_nbr(*head_a) == 1)
        ra(head_a);
    else if (biggest_nbr(*head_a) == 2)
        rra(head_a);
    if((*head_a)->nbr > (*head_a)->next->nbr)
        sa(*head_a);
}

void sort_four(t_node **head_a, t_node **head_b)
{
    get_totop_a(head_a, smalest_nbr(*head_a));
    pb(head_a, head_b);
    sort_three(head_a);
    pa(head_a, head_b);
}

void sort_five(t_node **head_a, t_node **head_b)
{
    get_totop_a(head_a, smalest_nbr(*head_a));
    pb(head_a, head_b);
    sort_four(head_a, head_b);
    pa(head_a, head_b); 
}


