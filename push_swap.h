#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_node
{
    int nbr;
    struct s_node *next;
}t_node;

char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s);
int		ft_strlen(char *str);
void	*ft_memcpy(void *dest, void *src, size_t n);
long	ft_atoi(char *nptr);
void sa(t_node *head_a);
void sb(t_node *head_b);
void ss(t_node *head_a, t_node *head_b);
void pa(t_node **head_a, t_node **head_b);
void pb(t_node **head_a, t_node **head_b);
void ra(t_node **head_a);
void rb(t_node **head_b);
void rr(t_node **head_a, t_node **head_b);
void rra(t_node **head_a);
void rrb(t_node **head_b);
void rrr(t_node **head_a, t_node **head_b);
void sort_two(t_node *head);
void sort_three(t_node *head_a,t_node *head_b);

#endif