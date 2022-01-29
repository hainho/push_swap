#include "pushswap.h"

static void	cal(t_pushswap *ps, t_node *node, int idx)
{
	if (node->bn[idx] == '0')
		pb(ps);
	else
		ra(ps);
	ps->count++;
	return;
}

static void	redix(t_pushswap *ps, int idx)
{
	int count;

	count = 0;
	while (count++ < ps->size)
		cal(ps,ps->a->head->next, idx);
	while (ps->b->length > 0)
	{
		pa(ps);
		ps->count++;
	}
}

void	redix_all(t_pushswap *ps)
{
	int	idx;

	idx = ps->length - 1;
	while (idx >= 0)
		redix(ps, idx--);
}