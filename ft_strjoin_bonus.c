/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:41:40 by iha               #+#    #+#             */
/*   Updated: 2022/06/06 04:41:40 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*join_str;
	char	*temp;
	int		len;
	int		idx;

	if (!(str1) && !(str2))
		return (NULL);
	if (!str1)
		return (ft_strdup(str2));
	if (!str2)
		return (ft_strdup(str1));
	idx = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	join_str = (char *)malloc(sizeof(char) * (len + 1));
	temp = join_str;
	if (join_str == NULL)
		return (NULL);
	while (str1[idx])
		*temp++ = str1[idx++];
	idx = 0;
	while (str2[idx])
		*temp++ = str2[idx++];
	*temp = '\0';
	return (join_str);
}
