/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:46:03 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 18:55:07 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

t_node	*new_node(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->bn = 0;
	node->next = NULL;
	node->prev = NULL;
	node->value = 0;
	return (node);
}

int	node_push_back(t_node *tail, t_node *node)
{
	t_node	*back;

	if (tail == NULL || node == NULL)
		return (-1);
	back = tail->prev;
	if (back == NULL)
		return (-1);
	back->next = node;
	node->prev = back;
	tail->prev = node;
	node->next = tail;
	return (0);
}

int	node_push_front(t_node *head, t_node *node)
{
	t_node	*front;

	if (head == NULL || node == NULL)
		return (-1);
	front = head->next;
	if (front == NULL)
		return (-1);
	front->prev = node;
	node->next = front;
	head->next = node;
	node->prev = head;
	return (0);
}

t_node	*node_pop_front(t_node *head)
{
	t_node	*front;
	t_node	*temp;

	if (head == NULL)
		return (NULL);
	if (head->next == NULL)
		return (NULL);
	front = head->next;
	temp = front->next;
	if (temp == NULL)
		return (NULL);
	head->next = temp;
	temp->prev = head;
	return (front);
}

t_node	*node_pop_back(t_node *tail)
{
	t_node	*back;
	t_node	*temp;

	if (tail == NULL)
		return (NULL);
	if (tail->prev == NULL)
		return (NULL);
	back = tail->prev;
	temp = back->prev;
	if (temp == NULL)
		return (NULL);
	tail->prev = temp;
	temp->next = tail;
	return (back);
}
