/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_watch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:40:37 by iha               #+#    #+#             */
/*   Updated: 2022/06/07 17:50:16 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	sqrt(int n)
{
	int	idx;

	if (n < 4)
		return (1);
	idx = 3;
	while (idx * idx < n)
		idx += 2;
	return (idx - 1);
}

int	cal_chunk(int size)
{
	int	chunk_size;

	chunk_size = sqrt(size);
	chunk_size += 2 * sqrt(chunk_size);
	return (chunk_size);
}

void	shift_a_to_b(t_pushswap *ps)
{
	int	chunk_size;

	chunk_size = cal_chunk(ps->a->length);
	while (ps->a->length)
	{
		if (ps->a->head->next->bn < ps->b->length)
		{
			pb(ps, 1);
			rb(ps, 1);
		}
		else if (ps->a->head->next->bn < ps->b->length + chunk_size)
			pb(ps, 1);
		else
			ra(ps, 1);
	}
}

static int	cal_direction(t_pushswap *ps)
{
	int		i;
	int		sum;
	t_node	*cur;

	i = 0;
	sum = 0;
	cur = ps->b->head->next;
	while (cur->bn + 1 != ps->b->length)
	{
		sum += cur->bn + 1;
		cur = cur->next;
		i++;
	}
	if (ps->b->length >= i * 2 + 1)
	{
		fix_outlier(ps, i, 1, sum);
		return (1);
	}
	i = ps->b->length - i;
	sum = ps->b->length * (ps->b->length + 3) - sum;
	fix_outlier(ps, i, 0, sum);
	return (0);
}

void	shift_b_to_a(t_pushswap *ps)
{
	while (ps->b->length)
	{
		if (cal_direction(ps) == 1)
		{
			while (ps->b->head->next->bn + 1 != ps->b->length && \
			ps->b->length)
				rb(ps, 1);
			pa(ps, 1);
		}
		else
		{
			while (ps->b->head->next->bn + 1 != ps->b->length && \
			ps->b->length)
				rrb(ps, 1);
			pa(ps, 1);
		}
	}
}
