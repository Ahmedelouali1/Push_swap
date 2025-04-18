/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmel-ou <ahmel-ou@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:39:13 by ahmel-ou          #+#    #+#             */
/*   Updated: 2025/03/29 17:19:03 by ahmel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
}					t_node;

char				*ft_strjoin(char *s1, char *s2);
char				**ft_split(char *s, char c);
char				*ft_strdup(char *s);
int					ft_strlen(char *str);
void				*ft_memcpy(void *dest, void *src, size_t n);
long				ft_atoi(char *nptr);
void				sa(t_node *head_a);
void				sb(t_node *head_b);
void				ss(t_node *head_a, t_node *head_b);
void				pa(t_node **head_a, t_node **head_b);
void				pb(t_node **head_a, t_node **head_b);
void				ra(t_node **head_a);
void				rb(t_node **head_b);
void				rr(t_node **head_a, t_node **head_b);
void				rra(t_node **head_a);
void				rrb(t_node **head_b);
void				rrr(t_node **head_a, t_node **head_b);
void				sort_two(t_node *head);
void				sort_three(t_node **head_a);
int					list_indexing(t_node *head);
int					is_sorted(t_node *head);
void				get_totop_a(t_node **head, int position);
int					count_list(t_node *head);
int					smalest_nbr(t_node *head);
void				sort_four(t_node **head_a, t_node **head_b);
void				sort_five(t_node **head_a, t_node **head_b);
void				print_list(t_node *head);
void				put_stack(t_node *head_a, t_node *head_b);
void				big_sort(t_node **head_a, t_node **head_b);
void				get_totop_b(t_node **head, int position);
void				push_chunk(t_node **head_a, t_node **head_b, int chunk_size,
						int step);
void				get_totop_b(t_node **head, int position);
int					biggest_nbr(t_node *head);
void				sort(t_node **head_a, t_node **head_b);
char				**delete(char **alloc);
int					check_args(char **split);
void				free_list(t_node *head_a);
int					valid_orno(char *str);
int					make_list(t_node **head_a, char *join, int i);
int					add_last(t_node **head, int nbr);
int					ft_error(char *join);
int					start_sort(t_node **head_a, t_node **head_b, char *join);
int					is_only_space(char *s);
void				write_error(void);

#endif