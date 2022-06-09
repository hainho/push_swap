/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:40:51 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 18:38:16 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	cal_pivot(t_deque *dq, int len, int pivot[2])
{
	t_node	*cur_node;
	int		min_bn;
	int		max_bn;

	min_bn = dq->head->next->bn;
	max_bn = min_bn;
	cur_node = dq->head->next->next;
	while (len-- > 1 && cur_node)
	{
		if (min_bn > cur_node->bn)
			min_bn = cur_node->bn;
		if (max_bn < cur_node->bn)
			max_bn = cur_node->bn;
		cur_node = cur_node->next;
	}
	pivot[0] = (max_bn - min_bn) / 3 + min_bn;
	pivot[1] = (max_bn - min_bn) / 3 * 2 + min_bn;
}

static void	rev_rotate_all(t_pushswap *ps, int left, int right)
{
	while (left > 0 || right > 0)
	{
		if (left > 0 && right > 0)
			rrr(ps, 1);
		else if (left > 0)
			rra(ps, 1);
		else if (right > 0)
			rrb(ps, 1);
		left--;
		right--;
	}
}

void	quick_a(t_pushswap *ps, int len)
{
	int	pivot[2];
	int	count[3];

	if (len <= 3)
		return (ps_sort_a(ps, len));
	cal_pivot(ps->a, len, pivot);
	shift_a_to_b(ps, len, count, pivot);
	rev_rotate_all(ps, count[2], count[1]);
	quick_a(ps, count[2]);
	quick_b(ps, count[1]);
	quick_b(ps, count[0]);
}

void	quick_b(t_pushswap *ps, int len)
{
	int	pivot[2];
	int	count[3];

	if (len <= 3)
		return (ps_sort_b(ps, len));
	cal_pivot(ps->b, len, pivot);
	shift_b_to_a(ps, len, count, pivot);
	quick_a(ps, count[2]);
	rev_rotate_all(ps, count[1], count[0]);
	quick_a(ps, count[1]);
	quick_b(ps, count[0]);
}
