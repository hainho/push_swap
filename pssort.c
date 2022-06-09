/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pssort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:30:13 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 15:45:01 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		pa(ps, 1);
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
