#include "pushswap.h"

static int		sqrt(int n)
{
	int idx;

	if (n < 4)
		return 1;
	idx = 3;
	while (idx * idx < n)
		idx += 2;
	return (idx - 1);
}

int		cal_chuck(int size)
{
	int chuck_size;

	chuck_size = sqrt(size);
	chuck_size += 2 * sqrt(chuck_size);
	return (chuck_size);
}

void	shift_a_to_b(t_pushswap *ps)
{
	int	chuck_size;

	chuck_size = cal_chuck(ps->a->length);
	while (ps->a->length)
	{
		if (ps->a->head->next->bn < ps->b->length)
		{
			pb(ps);
			rb(ps);
		}
		else if (ps->a->head->next->bn < ps->b->length + chuck_size)
			pb(ps);
		else
			ra(ps);
	}
}

int		cal_direction(t_pushswap *ps)
{
	int		idx;
	t_node	*cur;

	idx = 0;
	cur = ps->b->head->next;
	while (cur->bn + 1 != ps->b->length)
	{
		cur = cur->next;
		idx++;
	}
	if (ps->b->length >= idx * 2 + 1)
		return (1);
	return (0);
}

void	shift_b_to_a(t_pushswap *ps)
{
	while (ps->b->length)
	{
		if (cal_direction(ps) == 1)
		{
			while (ps->b->head->next->bn + 1 != ps->b->length)
				rb(ps);
			pa(ps);
		}
		else
		{
			while (ps->b->head->next->bn + 1 != ps->b->length)
				rrb(ps);
			pa(ps);
		}
	}
}
