/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:39 by iha               #+#    #+#             */
/*   Updated: 2022/06/06 00:19:14 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push(t_deque *src, t_deque *dst)
{
	t_node	*node;

	if (src->length == 0)
		return ;
	node = pop_front(src);
	if (node == NULL)
		return ;
	if (push_front(dst, node) == -1)
		return ;
	return ;
}

void	pa(t_pushswap *ps)
{
	push(ps->b, ps->a);
	ps->count++;

	return ;
}

void	pb(t_pushswap *ps)
{
	push(ps->a, ps->b);
	ps->count++;

	return ;
}
