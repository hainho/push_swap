#include "pushswap.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*dst;
	unsigned int	n;

	n = count * size;
	dst = malloc(n);
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, n);
	return (dst);
}
