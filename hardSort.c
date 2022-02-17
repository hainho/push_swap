/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:46:59 by iha               #+#    #+#             */
/*   Updated: 2022/02/17 10:47:01 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	three_sort(t_pushswap *ps, int base)
{
	if (ps->a->head->next->bn == base + 0)
	{
		if (ps->a->head->next->next->bn == base + 1)
			return (0);
		if (ps->a->head->next->next->bn == base + 2)
			rra(ps);
	}
	if (ps->a->head->next->bn == base + 1)
	{
		if (ps->a->head->next->next->bn == base + 0)
			sa(ps);
		if (ps->a->head->next->next->bn == base + 2)
			rra(ps);
	}
	if (ps->a->head->next->bn == base + 2)
	{
		if (ps->a->head->next->next->bn == base + 0)
			ra(ps);
		if (ps->a->head->next->next->bn == base + 1)
			sa(ps);
	}
	ps->count++;
	return (1);
}

void	three_sort_all(t_pushswap *ps, int base)
{
	while (three_sort(ps, base))
	{
		continue ;
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
			pb(ps);
		else
			ra(ps);
		ps->count++;
	}
	three_sort_all(ps, 2);
	if (ps->b->head->next->bn == 0)
		rb(ps);
	pa(ps);
	pa(ps);
	ps->count += 2;
	return ;
}
