/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:24 by iha               #+#    #+#             */
/*   Updated: 2022/02/17 15:04:26 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_pushswap	*ps;

	ps = new_pushswap();
	if (ps == NULL)
		return (-1);
	if (parsing(ps, argc, argv) == -1)
	{
		write(1, "Error\n", 6);
		return (free_pushswap(ps));
	}
	if (is_sorted(ps))
		return (0);
	if (ps->size == 3)
		three_sort_all(ps, 0);
	else if (ps->size == 5)
		five_sort_all(ps);
	else
		redix_all(ps);
	free_pushswap(ps);
	return (0);
}
