/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sand_watch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:40:37 by iha               #+#    #+#             */
/*   Updated: 2022/06/08 08:10:20 by iha              ###   ########.fr       */
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

static int	cal_chunk(int size)
{
	int	chunk_size;

	chunk_size = sqrt(size);
	chunk_size += 2 * sqrt(chunk_size);
	return (chunk_size);
}

void	shift_a_to_b(t_pushswap *ps)
{
	ps->chunk = cal_chunk(ps->size);
	while (ps->a->length)
	{
		if (ps->a->head->next->bn < ps->b->length)
		{
			pb(ps, 1);
			rb(ps, 1);
		}
		else if (ps->a->head->next->bn < ps->b->length + ps->chunk)
			pb(ps, 1);
		else
			ra(ps, 1);
	}
}

// static int	cal_direction(t_pushswap *ps)
// {
// 	int		i;
// 	int		sum;
// 	t_node	*cur;

// 	i = 0;
// 	sum = 0;
// 	cur = ps->b->head->next;
// 	while (cur->bn + 1 != ps->b->length)
// 	{
// 		sum += cur->bn + 1;
// 		cur = cur->next;
// 		i++;
// 	}
// 	if (ps->b->length >= i * 2 + 1)
// 	{
// 		fix_outlier(ps, i, 1, sum);
// 		return (1);
// 	}
// 	i = ps->b->length - i;
// 	sum = ps->b->length * (ps->b->length + 3) - sum;
// 	fix_outlier(ps, i, 0, sum);
// 	return (0);
// }

static int	cal_direction(t_pushswap *ps, int target)
{
	t_node	*r_node;
	t_node	*rr_node;

	if (ps->b->head->next->bn == target)
		return (1);
	r_node = ps->b->head->next->next;
	rr_node = ps->b->tail->prev;
	ps->outlier = 1;
	while (r_node->bn != target && rr_node->bn != target)
	{
		r_node = r_node->next;
		rr_node = rr_node->prev;
		ps->outlier++;
	}
	// printf("fix real target %d\n", target);
	if (r_node->bn == target)
	{
		fix_outlier(ps, 1);
		return (1);
	}
	else
		fix_outlier(ps, 0);
	return (0);
}

void	shift_b_to_a(t_pushswap *ps)
{
	int	target;

	while (ps->b->length)
	{
		if (ps->a->length > 0)
			target = ps->a->head->next->bn - 1;
		else
			target = ps->size - 1;
		if (cal_direction(ps, target) == 1)
		{
			while (ps->b->head->next->bn != target)
				rb(ps, 1);
			pa(ps, 1);
		}
		else
		{
			while (ps->b->head->next->bn != target)
				rrb(ps, 1);
			pa(ps, 1);
		}
	}
}
