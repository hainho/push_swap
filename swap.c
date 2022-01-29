#include "pushswap.h"

int	swap(t_deque *deque)
{
	t_node	*temp1;
	t_node	*temp2;
	t_node	*temp3;

	if (deque->length < 2)
		return (-1);
	temp1 = deque->head->next;
	temp2 = temp1->next;
	temp3 = temp2->next;
	temp1->next = temp3;
	temp3->prev = temp1;
	temp2->prev = deque->head;
	deque->head->next = temp2;
	temp1->prev = temp2;
	temp2->next = temp1;
	return (0);
}

int	push(t_deque *src, t_deque *dst)
{
	t_node	*node;

	if (src->length == 0)
		return (-1);
	if (node = pop_front(src) == NULL)
		return (-1);
	if (push_front(dst, node) == -1)
		return (-1);
	return (0);
}

int	rotate(t_deque *deque)
{
	t_node	*node;

	if (deque->length == 0)
		return (-1);
	if (node = pop_front(deque) == NULL)
		return (-1);
	if (push_back(deque, node) == -1)
		return (-1);
	return (0);
}

int	reverse_rotate(t_deque *deque)
{
	t_node	*node;

	if (deque->length == 0)
		return (-1);
	if (node = pop_back(deque) == NULL)
		return (-1);
	if (push_front(deque, node) == -1)
		return (-1);
	return (0);
}