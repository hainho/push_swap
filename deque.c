#include "pushswap.h"

t_deque	*new_deque(void)
{
	t_deque	*deque;

	deque = malloc(sizeof(t_deque));
	if (deque == NULL)
		return (NULL);
	deque->head = new_node();
	if (deque->head == NULL)
		return (NULL);
	deque->tail = new_node();
	if (deque->tail == NULL)
		return (NULL);
	deque->head->next = deque->tail;
	deque->tail->prev = deque->head;
	deque->length = 0;
	return (deque);
}

int	push_back(t_deque *deque, t_node *node)
{
	if (node_push_back(deque->tail, node) == -1)
		return (-1);
	(deque->length)++;
	return (0);
}

int	push_front(t_deque *deque, t_node *node)
{
	if (node_push_front(deque->head, node) == -1)
		return (-1);
	(deque->length)++;
	return (0);
}

t_node	*pop_back(t_deque *deque)
{
	t_node	*back;

	if (deque->length == 0)
		return (NULL);
	back = node_pop_back(deque->tail);
	if (back == NULL)
		return (NULL);
	(deque->length)--;
	return (back);
}

t_node	*pop_front(t_deque *deque)
{
	t_node	*front;

	if (deque->length == 0)
		return (NULL);
	front = node_pop_front(deque->head);
	if (front == NULL)
		return (NULL);
	(deque->length)--;
	return (front);
}
