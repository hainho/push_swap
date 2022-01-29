#include "pushswap.h"

static void	rotate(t_deque *deque)
{
	t_node	*node;

	if (deque->length == 0)
		return;
	if (node = pop_front(deque) == NULL)
		return;
	if (push_back(deque, node) == -1)
		return;
	return;
}

void	ra(t_pushswap *ps)
{
	rotate(ps->a);
	return;
}

void	rb(t_pushswap *ps)
{
	rotate(ps->b);
	return;
}

void	rr(t_pushswap *ps)
{
	ra(ps);
	rb(ps);
	return;
}