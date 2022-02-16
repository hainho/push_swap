#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_pushswap *ps;

	if ((ps = new_pushswap()) == NULL)
		return (-1);
	if (parsing(ps, argc, argv) == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	write(1, "parsing end\n", 12);

	print_a(ps);
	print_b(ps);

	if (ps->size == 3)
		three_sort_all(ps);
	else if (ps->size == 5)
		five_sort_all(ps);
	else
		redix_all(ps);

	print_a(ps);
	print_b(ps);

	printf("count : %d", ps->count);
	return (0);
}