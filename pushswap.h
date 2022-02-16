#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
typedef struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				bn;
	int				value;
}	t_node;

typedef struct	s_deque
{
	t_node	*head;
	t_node	*tail;
	int		length;
}	t_deque;

typedef struct s_pushswap
{
	t_deque	*a;
	t_deque	*b;
	int		size;
	int		count;
	int 	length;
}	t_pushswap;


t_node	*new_node();
int	node_push_back(t_node *tail, t_node *node);
int	node_push_front(t_node *head, t_node *node);
t_node	*node_pop_front(t_node *head);
t_node	*node_pop_back(t_node *tail);

t_deque	*new_deque();
int	push_back(t_deque *deque, t_node *node);
int	push_front(t_deque *deque, t_node *node);
t_node	*pop_back(t_deque *deque);
t_node	*pop_front(t_deque *deque);

t_pushswap	*new_pushswap();

void	sa(t_pushswap *ps);
void	sb(t_pushswap *ps);
void	ss(t_pushswap *ps);

void	pa(t_pushswap *ps);
void	pb(t_pushswap *ps);

void	ra(t_pushswap *ps);
void	rb(t_pushswap *ps);
void	rr(t_pushswap *ps);

void	rra(t_pushswap *ps);
void	rrb(t_pushswap *ps);
void	rrr(t_pushswap *ps);

int	ft_atoi(const char *str);
int	parsing(t_pushswap *ps, int argc, char **argv);
void	redix_all(t_pushswap *ps);

void	three_sort_all(t_pushswap* ps, int base);
void	five_sort_all(t_pushswap* ps);

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

void	print_a(t_pushswap *ps);
void	print_b(t_pushswap *ps);

#endif
