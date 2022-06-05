#include "pushswap.h"

void	ok_check(t_pushswap *ps)
{
	if (ps->b->length > 0)
		write(1, "KO\n", 3);
	else if (is_sorted(ps) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}