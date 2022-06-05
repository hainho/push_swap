/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:57 by iha               #+#    #+#             */
/*   Updated: 2022/06/06 00:18:56 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate(t_deque *deque)
{
	t_node	*node;

	if (deque->length == 0)
		return ;
	node = pop_front(deque);
	if (node == NULL)
		return ;
	if (push_back(deque, node) == -1)
		return ;
	return ;
}

void	ra(t_pushswap *ps)
{
	rotate(ps->a);
	ps->count++;

	return ;
}

void	rb(t_pushswap *ps)
{
	rotate(ps->b);
	ps->count++;

	return ;
}

void	rr(t_pushswap *ps)
{
	rotate(ps->a);
	rotate(ps->b);
	ps->count++;

	return ;
}
