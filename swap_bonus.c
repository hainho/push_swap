/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:46:44 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 18:53:42 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

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

void	sa(t_pushswap *ps, int is_print)
{
	swap(ps->a);
	if (is_print == 1)
		write(1, "sa\n", 3);
	return ;
}

void	sb(t_pushswap *ps, int is_print)
{
	swap(ps->b);
	if (is_print == 1)
		write(1, "sb\n", 3);
	return ;
}

void	ss(t_pushswap *ps, int is_print)
{
	swap(ps->a);
	swap(ps->b);
	if (is_print == 1)
		write(1, "ss\n", 3);
	return ;
}
