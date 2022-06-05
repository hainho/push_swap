/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iha <iha@student.42.kr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 04:42:09 by iha               #+#    #+#             */
/*   Updated: 2022/06/06 04:42:11 by iha              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_pushswap	*ps;
	int			rt;

	if (argc == 1)
		return (-1);
	ps = new_pushswap();
	if (ps == NULL)
		return (-1);
	if (parsing(ps, argc, argv) == -1)
	{
		write(1, "Error\n", 6);
		return (free_pushswap(ps));
	}
	rt = 0;
	while (rt == 0)
		rt = run_cmd(ps);
	if (rt == 1)
		ok_check(ps);
	else
		write(1, "Error\n", 6);
	free_pushswap(ps);
	return (0);
}
