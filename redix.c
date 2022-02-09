#include "pushswap.h"

static void	cal(t_pushswap *ps, t_node *node, int temp)
{
	if (node->bn % temp / (temp / 2) == 0)
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
	write(1, "cal end\n", 8);
	while (ps->b->length > 0)
	{
		pa(ps);
		ps->count++;
	}
	write(1, "pa end\n", 7);
}

void	redix_all(t_pushswap *ps)
{
	int	temp;
	int idx;

	idx = 0;
	temp = 2;
	printf("idx : %d\n", idx);
	while (idx++ < ps->length)
	{
		redix(ps, temp);
		temp *= 2;
	}
	write(1, "redix end\n", 10);
}