#include "pushswap.h"

static int	three_sort(t_pushswap* ps)
{
	if (ps->a->head->next->bn == 0)
	{
		if (ps->a->head->next->next->bn == 1)
			return (0);
		if (ps->a->head->next->next->bn == 2)
			rra(ps);
	}
	if (ps->a->head->next->bn == 1)
	{
		if (ps->a->head->next->next->bn == 0)
			sa(ps);
		if (ps->a->head->next->next->bn == 2)
			rra(ps);
	}
	if (ps->a->head->next->bn == 2)
	{
		if (ps->a->head->next->next->bn == 0)
			ra(ps);
		if (ps->a->head->next->next->bn == 1)
			sa(ps);
	}
	ps->count++;
	return (1);
}

void	three_sort_all(t_pushswap* ps)
{
	while (three_sort(ps))
	{
		continue;
	}
	return ;
}


void	five_sort_all(t_pushswap* ps)
{
	int	c;

	c = 5;
	while(c--)
	{
		if (ps->a->head->next->bn > 2)
			pb(ps);
		else
			ra(ps);
		ps->count++;
	}
	three_sort_all(ps);
	if (ps->b->head->next->bn == 3)
		rb(ps);
	pa(ps);
	pa(ps);
	ps->count += 2;
	return ;
}