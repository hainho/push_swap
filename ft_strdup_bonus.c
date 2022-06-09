/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:46:38 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 18:56:04 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

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
