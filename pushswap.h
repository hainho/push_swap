#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			*bn;
	int				value;
}	t_node;

typedef struct	s_deque
{
	struct s_node	*head;
	struct s_node	*tail;
	int				length;
}	t_deque;


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

#endif
