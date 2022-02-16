#include "pushswap.h"

t_pushswap	*new_pushswap(void)
{
	t_pushswap	*pushswap;

	pushswap = malloc(sizeof(t_pushswap));
	if (pushswap == NULL)
		return (NULL);
	pushswap->a = new_deque();
	if (pushswap->a == NULL)
		return (NULL);
	pushswap->b = new_deque();
	if (pushswap->b == NULL)
		return (NULL);
	pushswap->size = 0;
	pushswap->count = 0;
	pushswap->length = 0;
	return (pushswap);
}

void	print_a(t_pushswap *ps)
{
	t_node	*node;

	node = ps->a->head->next;
	while (node->next != NULL)
		node = node->next;
	return ;
}

void	print_b(t_pushswap *ps)
{
	t_node	*node;

	node = ps->b->head->next;
	while (node->next != NULL)
		node = node->next;
	return ;
}
