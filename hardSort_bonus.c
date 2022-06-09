/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardSort_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:46:59 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 19:07:38 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static int	three_sort(t_pushswap *ps, int base)
{
	if (ps->a->head->next->bn == base + 0)
	{
		if (ps->a->head->next->next->bn == base + 1)
			return (0);
		else if (ps->a->head->next->next->bn == base + 2)
			rra(ps, 1);
	}
	else if (ps->a->head->next->bn == base + 1)
	{
		if (ps->a->head->next->next->bn == base + 0)
			sa(ps, 1);
		else if (ps->a->head->next->next->bn == base + 2)
			rra(ps, 1);
	}
	else if (ps->a->head->next->bn == base + 2)
	{
		if (ps->a->head->next->next->bn == base + 0)
			ra(ps, 1);
		else if (ps->a->head->next->next->bn == base + 1)
			sa(ps, 1);
	}
	return (1);
}

void	three_sort_all(t_pushswap *ps, int base)
{
	while (three_sort(ps, base))
	{
	}
	return ;
}

void	five_sort_all(t_pushswap *ps)
{
	int	c;

	c = 5;
	while (c--)
	{
		if (ps->a->head->next->bn < 2)
			pb(ps, 1);
		else
			ra(ps, 1);
	}
	three_sort_all(ps, 2);
	if (ps->b->head->next->bn == 0)
		rb(ps, 1);
	pa(ps, 1);
	pa(ps, 1);
	return ;
}

int	is_sorted(t_deque *dq, int len)
{
	t_node	*cur;

	cur = dq->head->next;
	while (--len)
	{
		if (cur->value > cur->next->value)
			return (-1);
		cur = cur->next;
	}
	return (0);
}
