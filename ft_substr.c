/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:46:47 by iha               #+#    #+#             */
/*   Updated: 2022/02/17 10:46:48 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	size;

	if (s == NULL)
		return (NULL);
	while (*s && start)
	{
		s++;
		start--;
	}
	if (*s == 0)
		return (ft_strdup(""));
	size = ft_strlen(s);
	if (len > size)
		len = size;
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}
