/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:24 by iha               #+#    #+#             */
/*   Updated: 2022/06/06 07:17:08 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_pushswap	*ps;

	if (argc == 1)
		return (0);
	ps = new_pushswap();
	if (ps == NULL)
		return (-1);
	if (parsing(ps, argc, argv) == -1)
	{
		write(2, "Error\n", 6);
		return (free_pushswap(ps));
	}
	if (is_sorted(ps) == 0)
		return (free_pushswap(ps));
	if (ps->size == 3)
		three_sort_all(ps, 0);
	else if (ps->size == 5)
		five_sort_all(ps);
	else
	{
		shift_a_to_b(ps);
		shift_b_to_a(ps);
	}
	free_pushswap(ps);
	return (0);
}
