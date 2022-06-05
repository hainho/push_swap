/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:46:40 by iha               #+#    #+#             */
/*   Updated: 2022/02/17 10:46:42 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
