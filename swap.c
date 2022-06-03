/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:46:44 by iha               #+#    #+#             */
/*   Updated: 2022/06/04 06:53:01 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(t_deque *deque)
{
	t_node	*temp1;
	t_node	*temp2;
	t_node	*temp3;

	if (deque->length < 2)
		return ;
	temp1 = deque->head->next;
	temp2 = temp1->next;
	temp3 = temp2->next;
	temp1->next = temp3;
	temp3->prev = temp1;
	temp2->prev = deque->head;
	deque->head->next = temp2;
	temp1->prev = temp2;
	temp2->next = temp1;
	return ;
}

void	sa(t_pushswap *ps)
{
	swap(ps->a);
	write(1, "sa\n", 3);
	ps->count++;
	return ;
}

void	sb(t_pushswap *ps)
{
	swap(ps->b);
	write(1, "sb\n", 3);
	ps->count++;
	return ;
}

void	ss(t_pushswap *ps)
{
	swap(ps->a);
	swap(ps->b);
	write(1, "ss\n", 3);
	ps->count++;
	return ;
}
