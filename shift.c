/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:27:39 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 18:38:05 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	shift_a_mid(t_pushswap *ps, int len, int count[3], int pivot[2])
{
	pb(ps, 1);
	if (ps->a->head->next->bn > pivot[1] && len)
	{
		len--;
		rr(ps, 1);
		count[2]++;
	}
	else
		rb(ps, 1);
	count[1]++;
	return (len);
}

void	shift_a_to_b(t_pushswap *ps, int len, int count[3], int pivot[2])
{
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (len--)
	{
		if (ps->a->head->next->bn <= pivot[0])
		{
			pb(ps, 1);
			count[0]++;
		}
		else if (ps->a->head->next->bn <= pivot[1])
			len = shift_a_mid(ps, len, count, pivot);
		else
		{
			ra(ps, 1);
			count[2]++;
		}
	}
}

static int	shift_b_mid(t_pushswap *ps, int len, int count[3], int pivot[2])
{
	pa(ps, 1);
	if (ps->b->head->next->bn <= pivot[0] && len)
	{
		len--;
		rr(ps, 1);
		count[0]++;
	}
	else
		ra(ps, 1);
	count[1]++;
	return (len);
}

void	shift_b_to_a(t_pushswap *ps, int len, int count[3], int pivot[2])
{
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (len--)
	{
		if (ps->b->head->next->bn > pivot[1])
		{
			pa(ps, 1);
			count[2]++;
		}
		else if (ps->b->head->next->bn > pivot[0])
			len = shift_b_mid(ps, len, count, pivot);
		else
		{
			rb(ps, 1);
			count[0]++;
		}
	}
}
