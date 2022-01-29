#include "pushswap.h"

t_deque	*new_deque()
{
	t_deque	*deque;

	if (deque = malloc(sizeof(t_deque)) == NULL)
		return (NULL);
	if (deque->head = new_node() == NULL)
		return (NULL);
	if (deque->tail = new_node() == NULL)
		return (NULL);
	
}