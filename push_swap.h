#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

struct s_node
{
    struct s_node   *next;
    struct s_node   *prev;
    char            *bn;
    int             value;
};


#endif
