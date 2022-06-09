/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:46:40 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 18:56:21 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

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
