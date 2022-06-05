/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseRotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:54 by iha               #+#    #+#             */
/*   Updated: 2022/06/06 04:28:44 by iha              ###   ########.fr       */
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

void	rra(t_pushswap *ps, int is_print)
{
	reverse_rotate(ps->a);
	if (is_print == 1)
		write(1, "rra\n", 4);
	return ;
}

void	rrb(t_pushswap *ps, int is_print)
{
	reverse_rotate(ps->b);
	if (is_print == 1)
		write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_pushswap *ps, int is_print)
{
	reverse_rotate(ps->a);
	reverse_rotate(ps->b);
	if (is_print == 1)
		write(1, "rrr\n", 4);
	return ;
}
