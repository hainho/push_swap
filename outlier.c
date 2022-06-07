#include "pushswap.h"

int count_order = 0;

static void	pop_outlier(t_pushswap *ps, int direction, int target)
{
	if (direction == 1)
		while (ps->b->head->next->bn != target)
		{
			pa(ps, 1);
			ra(ps, 1);
            count_order+= 2;
		}
	else
	{
		while (ps->b->head->next->bn != target)
		{
			pa(ps, 1);
			ra(ps, 1);
			rrb(ps, 1);
            count_order+= 3;
		}
	}
}

static int	insertable(t_pushswap *ps, int idx, int target)
{
	t_node	*cur;
	
	cur = ps->a->tail->prev;
	while (idx > 0)
	{
		if (cur->bn + 1 == target)
			return (1);
		cur = cur->prev;
		idx--;
	}
	return (0);
}

static void	insert_outlier(t_pushswap *ps, int target)
{
	int	count;

	count = 0;
	while (ps->a->head->next->bn + 1 != target)
	{
		rra(ps, 1);
        count_order+= 1;
		count++;
	}
	pb(ps, 1);
    count_order+= 1;
	while (count > 1)
	{
		ra(ps, 1);
        count_order+= 1;
		count--;
	}
}

static void	rollback_outlier(t_pushswap *ps, int idx)
{
	int	count;
    int target;

	count = ps->b->length;
	while (count > 0)
	{
		target = ps->b->head->next->bn;
		rb(ps, 1);
        count_order+= 1;
		if (insertable(ps, idx, target) == 1)
		{
			insert_outlier(ps, target);
			continue;
		}
		count--;
	}
}

// static void	print_b(t_pushswap *ps)
// {
// 	t_node *node;

// 	node = ps->b->head->next;
// 	while(node->next)
// 	{
// 		printf("count    before %d\n", node->bn);
// 		node = node->next;
// 	}
// }

// static void	print_b2(t_pushswap *ps)
// {
// 	t_node *node;

// 	node = ps->b->head->next;
// 	while(node->next)
// 	{
// 		printf("count   after  %d\n", node->bn);
// 		node = node->next;
// 	}
// }

void	fix_outlier(t_pushswap *ps, int idx, int direction)
{
    int target;
    count_order = 0;
    target = ps->b->length - 1;
    // print_b(ps);

	pop_outlier(ps, direction, target);
	rollback_outlier(ps, idx);

    // print_b2(ps);

    // printf("count : %d    %d\n", count_order, ps->b->length);
}