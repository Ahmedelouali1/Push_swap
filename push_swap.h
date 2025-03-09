#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


struct	s_node
{
    int nbr;
    struct s_node *next;
};

char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s);
int		ft_strlen(char *str);
void	*ft_memcpy(void *dest, void *src, size_t n);
long	ft_atoi(char *nptr);

#endif