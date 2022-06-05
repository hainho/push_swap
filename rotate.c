/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:57 by iha               #+#    #+#             */
/*   Updated: 2022/06/06 04:28:50 by iha              ###   ########.fr       */
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

void	ra(t_pushswap *ps, int is_print)
{
	rotate(ps->a);
	if (is_print == 1)
		write(1, "ra\n", 3);
	return ;
}

void	rb(t_pushswap *ps, int is_print)
{
	rotate(ps->b);
	if (is_print == 1)
		write(1, "rb\n", 3);
	return ;
}

void	rr(t_pushswap *ps, int is_print)
{
	rotate(ps->a);
	rotate(ps->b);
	if (is_print == 1)
		write(1, "rr\n", 3);
	return ;
}
