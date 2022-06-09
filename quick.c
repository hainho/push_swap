/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:40:51 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 13:59:11 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	cal_pivot(t_deque *dq, int length, int pivot[2])
{
	t_node	*cur_node;
	int		min_bn;
	int		max_bn;

	min_bn = dq->head->next->bn;
	max_bn = min_bn;
	cur_node = dq->head->next->next;
	while (length-- > 1 && cur_node)
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

void	rev_rotate_all(t_pushswap *ps, int left, int right)
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

void	shift_a_to_b(t_pushswap *ps, int length, int count[3], int pivot[2])
{
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (length--)
	{
		if (ps->a->head->next->bn <= pivot[0])
		{
			pb(ps, 1);
			count[0]++;
		}
		else if (ps->a->head->next->bn <= pivot[1])
		{
			pb(ps, 1);
			if (ps->a->head->next->bn > pivot[1] && length)
			{
				length--;
				rr(ps, 1);
				count[2]++;
			}
			else
				rb(ps ,1);
			count[1]++;
		}
		else
		{
			ra(ps, 1);
			count[2]++;
		}
	}
}

void	shift_b_to_a(t_pushswap *ps, int length, int count[3], int pivot[2])
{
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (length--)
	{
		if (ps->b->head->next->bn > pivot[1])
		{
			pa(ps, 1);
			count[2]++;
		}
		else if (ps->b->head->next->bn > pivot[0])
		{
			pa(ps, 1);
			if (ps->b->head->next->bn <= pivot[0] && length)
			{
				length--;
				rr(ps, 1);
				count[0]++;
			}
			else
				ra(ps ,1);
			count[1]++;
		}
		else
		{
			rb(ps, 1);
			count[0]++;
		}
	}
}

void	ps_sort_a(t_pushswap *ps, int len)
{
	if (len == 2 && is_sorted(ps->a, 2) == -1)
		sa(ps, 1);
	if (len == 3 && is_sorted(ps->a, 3) == -1)
	{
		if (ps->a->head->next->bn > ps->a->head->next->next->bn)
			sa(ps, 1);
		if (is_sorted(ps->a, 3) == -1)
		{
			ra(ps, 1);
			sa(ps, 1);
			rra(ps, 1);
		}
		if (is_sorted(ps->a, 3) == -1)
			sa(ps, 1);
	}
}

void	ps_sort_b(t_pushswap *ps, int len)
{
	if (len == 1)
		pa(ps ,1);
	else if (len == 2)
	{
		if (rev_is_sorted(ps->b, 2) == -1)
			sb(ps, 1);
		pa(ps, 1);
		pa(ps, 1);
	}
	else if (len == 3)
	{
		if (ps->b->head->next->bn < ps->b->head->next->next->bn)
			sb(ps, 1);
		pa(ps, 1);
		if (ps->b->head->next->bn < ps->b->head->next->next->bn)
			sb(ps, 1);
		pa(ps, 1);
		if (ps->a->head->next->bn > ps->a->head->next->next->bn)
			sa(ps, 1);
		pa(ps, 1);
	}
}

void	quick_a(t_pushswap *ps, int length)
{
	int	pivot[2];
	int	count[3];

	if (length <= 3)
	{
		ps_sort_a(ps, length);
		return ;
	}
	cal_pivot(ps->a, length, pivot);
	shift_a_to_b(ps, length, count, pivot);
	rev_rotate_all(ps, count[2], count[1]);
	quick_a(ps, count[2]);
	quick_b(ps, count[1]);
	quick_b(ps, count[0]);
}

void	quick_b(t_pushswap *ps, int length)
{
	int	pivot[2];
	int	count[3];

	if (length <= 3)
		return (ps_sort_b(ps, length));
	cal_pivot(ps->b, length, pivot);
	shift_b_to_a(ps, length, count, pivot);
	quick_a(ps, count[2]);
	rev_rotate_all(ps, count[1], count[0]);
	quick_a(ps, count[1]);
	quick_b(ps, count[0]);
}
