#include "pushswap.h"

t_pushswap	*new_pushswap()
{
	t_pushswap	*pushswap;

	if ((pushswap = malloc(sizeof(t_pushswap))) == NULL)
		return (NULL);
	if ((pushswap->a = new_deque()) == NULL)
		return (NULL);
	if ((pushswap->b = new_deque()) == NULL)
		return (NULL);
	pushswap->size = 0;
	pushswap->count = 0;
	pushswap->length = 0;
	return (pushswap);
}

void	print_a(t_pushswap *ps)
{
	t_node* node;
	
	node = ps->a->head->next;
	while (node->next != NULL)
	{
		printf("a node : %d\n", node->bn);
		node = node->next;
	}
}

void	print_b(t_pushswap *ps)
{
	t_node* node;
	
	node = ps->b->head->next;
	while (node->next != NULL)
	{
		printf("b node : %d\n", node->bn);
		node = node->next;
	}
}