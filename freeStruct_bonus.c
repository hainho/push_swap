/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeStruct_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:46:21 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 18:56:34 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	free_deque(t_deque *dq)
{
	t_node	*cur;
	t_node	*temp;

	cur = dq->head;
	while (cur)
	{
		temp = cur;
		cur = cur->next;
		free(temp);
	}
	if (dq != NULL)
		free(dq);
	return ;
}

int	free_pushswap(t_pushswap *ps)
{
	if (ps->a != NULL)
		free_deque(ps->a);
	if (ps->b != NULL)
		free_deque(ps->b);
	if (ps != NULL)
		free(ps);
	return (-1);
}

int	free_split(char **sp)
{
	int		ptr;

	ptr = 0;
	while (sp[ptr])
	{
		free(sp[ptr++]);
	}
	free(sp);
	return (-1);
}
