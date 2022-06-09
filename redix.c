/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:49 by iha               #+#    #+#             */
/*   Updated: 2022/06/08 05:37:28 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	cal(t_pushswap *ps, t_node *node, int temp)
{
	if (node->bn % temp / (temp / 2) == 0)
		pb(ps, 1);
	else
		ra(ps, 1);
	return ;
}

static void	redix(t_pushswap *ps, int idx)
{
	int	count;

	count = 0;
	while (count++ < ps->size)
		cal(ps, ps->a->head->next, idx);
	while (ps->b->length > 0)
		pa(ps, 1);
	return ;
}

void	redix_all(t_pushswap *ps)
{
	int	temp;
	int	idx;

	idx = 0;
	temp = 2;
	while (idx++ < ps->size)
	{
		redix(ps, temp);
		temp *= 2;
	}
	return ;
}
