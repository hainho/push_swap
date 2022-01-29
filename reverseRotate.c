#include "pushswap.h"

static void	reverse_rotate(t_deque *deque)
{
	t_node	*node;

	if (deque->length == 0)
		return;
	if (node = pop_back(deque) == NULL)
		return;
	if (push_front(deque, node) == -1)
		return;
	return;
}

void	rra(t_pushswap *ps)
{
	reverse_rotate(ps->a);
	return;
}

void	rrb(t_pushswap *ps)
{
	reverse_rotate(ps->b);
	return;
}

void	rrr(t_pushswap *ps)
{
	rra(ps);
	rrb(ps);
	return;
}
