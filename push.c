#include "pushswap.h"

static void	push(t_deque *src, t_deque *dst)
{
	t_node	*node;

	if (src->length == 0)
		return;
	if ((node = pop_front(src)) == NULL)
		return;
	if (push_front(dst, node) == -1)
		return;
	return;
}

void	pa(t_pushswap *ps)
{
	push(ps->b, ps->a);
	write(1, "pa\n", 3);
	return;
}

void	pb(t_pushswap *ps)
{
	push(ps->a, ps->b);
	write(1, "pb\n", 3);
	return;
}