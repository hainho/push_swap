#include "pushswap.h"

static void	swap(t_deque *deque)
{
	t_node	*temp1;
	t_node	*temp2;
	t_node	*temp3;

	if (deque->length < 2)
		return;
	temp1 = deque->head->next;
	temp2 = temp1->next;
	temp3 = temp2->next;
	temp1->next = temp3;
	temp3->prev = temp1;
	temp2->prev = deque->head;
	deque->head->next = temp2;
	temp1->prev = temp2;
	temp2->next = temp1;
	return;
}

void	sa(t_pushswap *ps)
{
	swap(ps->a);
	return;
}

void	sb(t_pushswap *ps)
{
	swap(ps->b);
	return;
}

void	ss(t_pushswap *ps)
{
	swap(ps->a);
	swap(ps->b);
	return;
}
