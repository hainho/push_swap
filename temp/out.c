/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:52:20 by iha               #+#    #+#             */
/*   Updated: 2022/06/08 08:21:02 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	pop_outlier(t_pushswap *ps, int direction)
{
	int	count;

	count = ps->outlier;
	while (count > 0)
	{
		if (direction == 1)
			pa(ps, 1);
		else
		{
			pa(ps, 1);
			rrb(ps, 1);
		}
		count--;
	}
}

static int	insertable(t_pushswap *ps, int target)
{
	int		count;
	t_node	*cur;

	count = ps->outlier;
	cur = ps->a->head->next;
	while (count > 0)
	{
		if (cur->bn == target)
			return (1);
		count--;
		cur = cur->next;
	}
	return (0);
}

static void	insert_outlier(t_pushswap *ps, int target)
{
	int	count;

	count = ps->outlier;
	while (count > 0)
	{
		count--;
		if (ps->a->head->next->bn == target)
		{
			pb(ps, 1);
			ps->outlier--;
			break;
		}
		else
			ra(ps, 1);
	}
	while (count < ps->outlier)
	{
		count++;
		rra(ps, 1);
	}
}

static void	rollback_outlier(t_pushswap *ps)
{
	int	count;

	count = ps->b->length;
	while (count > 0)
	{
		printf("fix?? %d\n", ps->b->head->next->bn - 1);
		if (insertable(ps, ps->b->head->next->bn - 1) == 1)
		{
			rb(ps, 1);
			printf("fix target %d\n", ps->b->tail->prev->bn - 1);

			insert_outlier(ps, ps->b->tail->prev->bn - 1);
			continue ;
		}
		rb(ps, 1);
		count--;
	}
}


static void	print_b(t_pushswap *ps)
{
	t_node *node;

	node = ps->b->head->next;
	while(node->next)
	{
		printf("fix %d\n", node->bn);
		node = node->next;
	}
}

int		cal_sum(t_pushswap *ps, int direction)
{
	int		sum;
	int		count;
	t_node	*temp;

	if (ps->outlier == 0)
		return (0);
	sum = ps->b->head->next->bn;
	count = ps->outlier - 1;
	if (direction == 1)
		temp = ps->b->head->next;
	else
		temp = ps->b->tail->prev;
	while (count-- > 0)
	{
		if (direction == 1)
			temp = temp -> next;
		else
			temp = temp->prev;
		sum += temp->bn;
	}
	return (sum);
}

void	fix_outlier(t_pushswap *ps, int direction)
{
	int sum;

	sum = cal_sum(ps, direction);
	if (ps->outlier * ps->b->length - sum > ps->outlier * ps->outlier + ps->b->length)
	{
	printf("fix outlier %d  length %d   sum %d\n", ps->outlier, ps->b->length, sum);

		printf("fix before\n");
		print_b(ps);

		pop_outlier(ps, direction);
		rollback_outlier(ps);
		printf("fix after\n");
		print_b(ps);
	}
}
