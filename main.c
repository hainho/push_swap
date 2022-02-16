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

	redix_all(ps);

	print_a(ps);
	print_b(ps);
	return (0);
}