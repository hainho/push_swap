#include "pushswap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		srcsize;

	if (dst == 0 || src == 0)
		return (0);
	srcsize = ft_strlen(src);
	if (srcsize + 1 < dstsize)
		ft_memcpy(dst, src, srcsize + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (srcsize);
}