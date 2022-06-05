/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:40:51 by iha               #+#    #+#             */
/*   Updated: 2022/06/06 04:40:51 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		get_min_bn(t_pushswap *ps)
{
	t_node	*cur_node;
	int		min_bn;

	min_bn = ps->a->head->next->bn;
	cur_node = ps->a->head->next->next;
	while (cur_node->next)
	{
		if (min_bn > cur_node->bn)
			min_bn = cur_node->bn;
		cur_node = cur_node->next;
	}
	return min_bn;
}

int		cal_pivot(t_pushswap *ps)
{
	t_node	*cur_node;
	int		min_bn;
	int		max_bn;

	min_bn = ps->a->head->next->bn;
	max_bn = min_bn;
	cur_node = ps->a->head->next->next;
	while (cur_node->next)
	{
		if (min_bn > cur_node->bn)
			min_bn = cur_node->bn;
		if (max_bn < cur_node->bn)
			max_bn = cur_node->bn;
		cur_node = cur_node->next;
	}
	return ((max_bn + min_bn) / 2);
}

void	shift_with_order(t_pushswap *ps, int count)
{
	while (count--)
	{
		pb(ps, 1);
		rb(ps, 1);
	}
}

void	shift_with_reverse(t_pushswap *ps, int count)
{
	int	temp;

	temp = count;
	while (temp--)
		pb(ps, 1);
	while (count--)
		rb(ps, 1);
}

void	sort_a_3(t_pushswap *ps)
{
	int		min_bn;

	min_bn = get_min_bn(ps);
	if (ps->a->head->next->bn == min_bn)
	{
		if (ps->a->head->next->next->bn == min_bn + 2)
			ra(ps, 1);
	}
	else if (ps->a->head->next->bn == min_bn + 1)
	{
		if (ps->a->head->next->next->bn == min_bn + 2)
			rra(ps, 1);
		else
			sa(ps, 1);
	}
	else
	{
		if (ps->a->head->next->next->bn == min_bn)
			ra(ps, 1);
	}
	if (ps->a->head->next->bn == min_bn)
		shift_with_order(ps, 3);
	else
		shift_with_reverse(ps, 3);
}

void	shift_a(t_pushswap *ps)
{
	if (ps->a->length == 3)
		sort_a_3(ps);
	else if (ps->a->length == 2)
	{
		if (ps->a->head->next->bn < ps->a->head->next->next->bn)
			shift_with_order(ps, 2);
		else
			shift_with_reverse(ps, 2);
	}
	else if (ps->a->length == 1)
	{
		pb(ps, 1);
		rb(ps, 1);
	}
}

void	quick_a(t_pushswap *ps)
{
	int	pivot;
	int	stack;
	int	count;

	if (ps->a->length <= 3)
	{
		shift_a(ps);
		return;
	}
	stack = 0;
	count = ps->a->length;
	pivot = cal_pivot(ps);
	while (count--)
	{
		if (ps->a->head->next->bn > pivot)
		{
			pb(ps, 1);
			stack++;
		}
		else
			ra(ps, 1);
	}
	quick_a(ps);
	while (stack--)
		pa(ps, 1);
	quick_a(ps);
}
