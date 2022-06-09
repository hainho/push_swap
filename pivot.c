#include "pushswap.h"

static int	get_min_bn(t_deque *dq, int target)
{
	t_node	*cur_node;
	int		min_bn;
	int		max_bn;

	min_bn = dq->head->next->bn;
	max_bn = min_bn;
	cur_node = dq->head->next->next;
	while (target--)
	{
		if (min_bn > cur_node->bn)
			min_bn = cur_node->bn;
		if (max_bn < cur_node->bn)
			max_bn = cur_node->bn;
		cur_node = cur_node->next;
	}
	return ((max_bn + min_bn) / 2);
}

static void	cal_pivot(t_deque *dq, int target, int *pivot)
{
	t_node	*cur_node;
	int		min_bn;
	int		max_bn;

	min_bn = dq->head->next->bn;
	max_bn = min_bn;
	cur_node = dq->head->next->next;
	while (target--)
	{
		if (min_bn > cur_node->bn)
			min_bn = cur_node->bn;
		if (max_bn < cur_node->bn)
			max_bn = cur_node->bn;
		cur_node = cur_node->next;
	}
	pivot[0] = (max_bn - min_bn) / 3
	pivot[1] = pivot[0] * 2
}