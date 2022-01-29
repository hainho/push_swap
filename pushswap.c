#include "pushswap.h"

t_pushswap	*new_pushswap()
{
	t_pushswap	*pushswap;

	if (pushswap = malloc(sizeof(t_pushswap)) == NULL)
		return (NULL);
	if (pushswap->a = new_deque() == NULL)
		return (NULL);
	if (pushswap->a = new_deque() == NULL)
		return (NULL);
	pushswap->size = 0;
	return (pushswap);
}