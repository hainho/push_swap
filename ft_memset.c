#include "pushswap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	unsigned char	uc;

	uc = c;
	temp = b;
	while (len--)
		*temp++ = c;
	return (b);
}