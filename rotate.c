#include "pushswap.h"

static void	rotate(t_deque *deque)
{
	t_node	*node;

	if (deque->length == 0)
		return;
	if ((node = pop_front(deque)) == NULL)
		return;
	if (push_back(deque, node) == -1)
		return;
	return;
}

void	ra(t_pushswap *ps)
{
	rotate(ps->a);
	write(1, "ra\n", 3);
	return;
}

void	rb(t_pushswap *ps)
{
	rotate(ps->b);
	write(1, "rb\n", 3);
	return;
}

void	rr(t_pushswap *ps)
{
	rotate(ps->a);
	rotate(ps->b);
	write(1, "rr\n", 3);
	return;
}