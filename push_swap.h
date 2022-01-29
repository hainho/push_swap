#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
struct s_node
{
    struct s_node   *next;
    struct s_node   *prev;
    char            *bn;
    int             value;
}   t_node;

struct s_node  *new_node();
int push_back(struct s_node *tail, struct s_node *node);
int push_front(struct s_node *head, struct s_node *node);
struct s_node   *pop_front(struct s_node *head);
struct s_node   *pop_back(struct s_node *tail);

#endif
