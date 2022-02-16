#include "pushswap.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*temp;
	char	*dst;

	size = ft_strlen(s1);
	dst = (char *)malloc((size + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	temp = dst;
	while (size--)
		*temp++ = *s1++;
	*temp = 0;
	return (dst);
}
