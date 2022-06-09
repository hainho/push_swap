/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:45 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 18:54:48 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

t_pushswap	*new_pushswap(void)
{
	t_pushswap	*pushswap;

	pushswap = malloc(sizeof(t_pushswap));
	if (pushswap == NULL)
		return (NULL);
	pushswap->a = new_deque();
	if (pushswap->a == NULL)
	{
		free_pushswap(pushswap);
		return (NULL);
	}
	pushswap->b = new_deque();
	if (pushswap->b == NULL)
	{
		free_pushswap(pushswap);
		return (NULL);
	}
	pushswap->size = 0;
	pushswap->count = 0;
	pushswap->outlier = 0;
	return (pushswap);
}
