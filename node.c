#include "push_swap.h"

struct s_node  *new_node()
{
    struct s_node   *node;

    if (node = malloc(sizeof(struct s_node)) == NULL)
        return (NULL);
    node->bn = NULL;
    node->next = NULL;
    node->prev = NULL;
    node->value = 0;
    return (node);
}

int push_back(struct s_node *tail, struct s_node *node)
{
    struct s_node   *back;

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

int push_front(struct s_node *head, struct s_node *node)
{
    struct s_node   *front;

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

struct s_node   *pop_front(struct s_node *head)
{
    if (head == NULL)
        return (NULL);
    return (head->next);    
}

struct s_node   *pop_back(struct s_node *tail)
{
    if (tail == NULL)
        return (NULL);
    return (tail->prev);    
}