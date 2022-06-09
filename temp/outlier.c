/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outlier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:52:20 by iha               #+#    #+#             */
/*   Updated: 2022/06/08 05:37:22 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	pop_outlier(t_pushswap *ps, int direction, int target)
{
	if (direction == 1)
	{
		while (ps->b->head->next->bn != target)
		{
			pa(ps, 1);
			ra(ps, 1);
		}
	}
	else
	{
		while (ps->b->head->next->bn != target)
		{
			pa(ps, 1);
			ra(ps, 1);
			rrb(ps, 1);
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
		count++;
	}
	pb(ps, 1);
	while (count > 1)
	{
		ra(ps, 1);
		count--;
	}
}

static void	rollback_outlier(t_pushswap *ps, int idx)
{
	int	count;
	int	target;

	count = ps->b->length;
	while (count > 0)
	{
		target = ps->b->head->next->bn;
		rb(ps, 1);
		if (insertable(ps, idx, target) == 1)
		{
			insert_outlier(ps, target);
			continue ;
		}
		count--;
	}
}

void	fix_outlier(t_pushswap *ps, int i, int direction, int sum)
{
	int	target;
	int	chunk;

	target = ps->b->length - 1;
	chunk = cal_chunk(ps->size);
	if (i * (i + 1) + target < (target - i) * i - sum && i > chunk / 5)
	{
		pop_outlier(ps, direction, target);
		rollback_outlier(ps, i);
	}
}
