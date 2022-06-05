/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:39 by iha               #+#    #+#             */
/*   Updated: 2022/06/06 04:28:33 by iha              ###   ########.fr       */
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

void	pa(t_pushswap *ps, int is_print)
{
	push(ps->b, ps->a);
	if (is_print == 1)
		write(1, "pa\n", 3);
	return ;
}

void	pb(t_pushswap *ps, int is_print)
{
	push(ps->a, ps->b);
	if (is_print == 1)
		write(1, "pb\n", 3);
	return ;
}
