#include "pushswap.h"

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
	free(dq);
	return ;
}

int	free_pushswap(t_pushswap *ps)
{
	free_deque(ps->a);
	free_deque(ps->b);
	free(ps);
	return (-1);
}
