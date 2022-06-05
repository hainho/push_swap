/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:54 by iha               #+#    #+#             */
/*   Updated: 2022/06/06 00:19:06 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	reverse_rotate(t_deque *deque)
{
	t_node	*node;

	if (deque->length == 0)
		return ;
	node = pop_back(deque);
	if (node == NULL)
		return ;
	if (push_front(deque, node) == -1)
		return ;
	return ;
}

void	rra(t_pushswap *ps)
{
	reverse_rotate(ps->a);
	ps->count++;

	return ;
}

void	rrb(t_pushswap *ps)
{
	reverse_rotate(ps->b);
	ps->count++;

	return ;
}

void	rrr(t_pushswap *ps)
{
	reverse_rotate(ps->a);
	reverse_rotate(ps->b);
	ps->count++;

	return ;
}
