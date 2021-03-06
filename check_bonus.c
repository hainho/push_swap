/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:42:14 by iha               #+#    #+#             */
/*   Updated: 2022/06/09 18:57:13 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	ok_check(t_pushswap *ps)
{
	if (ps->b->length > 0)
		write(1, "KO\n", 3);
	else if (is_sorted(ps->a, ps->size) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
